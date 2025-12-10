from google.colab import files
from ortools.sat.python import cp_model
import sys

# ==========================
# Funciones de parsing
# ==========================

def contar_botones(line: str) -> int:
    """
    Cuenta cuántos '(' hay antes del primer '{'.
    Igual que contarBotones en C++.
    """
    c1 = line.find('{')
    count = 0
    for i in range(c1):
        if line[i] == '(':
            count += 1
    return count


def resolver_maquina(line: str) -> int:
    """
    Traducción del cuerpo del while(getline) de tu C++,
    pero usando OR-Tools en vez de Eigen y además
    MINIMIZANDO el número total de pulsaciones (sum(x)).

    Devuelve la suma mínima de pulsaciones para esa máquina.
    """
    line = line.strip()
    if not line:
        return 0

    # ---------------------------
    # SACO JOLTAGE (entre { ... })
    # ---------------------------
    c1 = line.find('{')
    c2 = line.find('}')
    if c1 == -1 or c2 == -1 or c2 <= c1:
        print("Línea sin llaves { }:", line, file=sys.stderr)
        return 0

    j = line[c1 + 1:c2]         # contenido entre { y }
    j = j.replace(',', ' ')
    joltage = [int(tok) for tok in j.split()]
    m = len(joltage)

    # ---------------------------
    # SACO LOS BOTONES
    # ---------------------------
    n = contar_botones(line)
    boton = [[0] * m for _ in range(n)]  # boton[botón][contador]

    tokens = line.split()
    if not tokens:
        return 0

    # Primer token = basura (tipo "[...###.#.#]")
    idx = 1
    cont = 0

    while idx < len(tokens):
        l = tokens[idx]

        # En cuanto empieza con '{', estamos en la parte de joltage
        if l[0] == '{':
            break

        # En C++:
        #   l = l.substr(1, l.size() - 2);
        #   luego reemplaza ',' por ' ' y hace stringstream bb(l)
        if len(l) >= 2 and l[0] == '(' and l[-1] == ')':
            inside = l[1:-1].replace(',', ' ')
            for tok in inside.split():
                a = int(tok)
                if 0 <= a < m:
                    boton[cont][a] = 1
                else:
                    print(f"Índice fuera de rango: {a} (m={m})", file=sys.stderr)
        # Si no cumple formato "(...)" lo ignoramos, igual que hacía C++ de facto

        cont += 1
        idx += 1
        if cont >= n:
            break

    # ==========================
    # MODELO Aᵗ * x = B, x >= 0
    # MINIMIZAR sum(x)
    # ==========================
    model = cp_model.CpModel()

    # Cota superior burra: como cada pulsación suma al menos 1 a algún contador,
    # no tiene sentido pulsar más veces que la suma total de B.
    max_presses = sum(joltage) if joltage else 0
    if max_presses == 0:
        # Todo B es 0, solución trivial x = 0
        print("0" * n)
        print("Suma de x:", 0)
        return 0

    X = [model.NewIntVar(0, max_presses, f"x{i}") for i in range(n)]

    # Restricciones: para cada contador k:
    # sum_j A[k][j] * x_j = B[k]
    # Pero nuestra estructura es boton[botón][contador]
    # => coef = boton[j][k]
    for k in range(m):
        terms = []
        for j_btn in range(n):
            if boton[j_btn][k] != 0:
                terms.append(X[j_btn])
        if terms:
            model.Add(sum(terms) == joltage[k])
        else:
            # Si ningún botón toca ese contador, B[k] debe ser 0
            model.Add(joltage[k] == 0)

    # Objetivo: minimizar número total de pulsaciones
    model.Minimize(sum(X))

    solver = cp_model.CpSolver()
    # (opcional) limita tiempo si quieres
    # solver.parameters.max_time_in_seconds = 10

    status = solver.Solve(model)

    if status not in (cp_model.OPTIMAL, cp_model.FEASIBLE):
        print("No hay solución exacta para esta máquina. Status:",
              solver.StatusName(), file=sys.stderr)
        return 0

    x_vals = [solver.Value(var) for var in X]

    # Imprimir vector x como hacía el C++ (Eigen << x)
    # Aquí lo imprimimos en una sola línea separado por espacios.
    print(" ".join(str(v) for v in x_vals))
    suma = sum(x_vals)
    print("Suma de x:", suma)

    return suma


# ==========================
# Lógica de Colab: subir archivo y procesar
# ==========================

print("Sube el archivo de input (el tocho con todas las máquinas)...")
uploaded = files.upload()

filename = list(uploaded.keys())[0]
print("Usando archivo:", filename)

total_global = 0
with open(filename, 'r') as f:
    for line in f:
        if line.strip():
            total_global += resolver_maquina(line)

print("\nTOTAL:", total_global)
