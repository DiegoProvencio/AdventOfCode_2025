#include <bits/stdc++.h>
using namespace std;

struct Nodo{
    string nombre;
    vector<Nodo*> hijos;

    Nodo() {}
    Nodo(const string& n) : nombre(n) {}
};

unordered_map<string, Nodo*> grafo;
unordered_map<Nodo*, long long> dp[2][2];

Nodo* getNodo(const string& nombre) 
{
    if (!grafo.count(nombre))
        grafo[nombre] = new Nodo(nombre);
    return grafo[nombre];
}

long long dfs(Nodo* u, bool visto_dac, bool visto_fft) 
{
    long long &res = dp[visto_dac][visto_fft][u];
    if (res != -1)
        return res;

    bool nd = 0;
    	if (visto_dac || (u->nombre == "dac")) nd = 1;
    bool nf = 0;
    	if (visto_fft || (u->nombre == "fft")) nf = 1;

    if (u->nombre == "out")
        return ((nd == 1 && nf ==1) ? 1 : 0);

    long long total = 0;
    for (Nodo* v : u->hijos)
        total += dfs(v, nd, nf);

    return res = total;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) 
    {
        stringstream ss(line);
        string name;
        ss >> name;

        Nodo* a = getNodo(name.substr(0, 3));

        string hijo;
        while (ss >> hijo) 
        {
            Nodo* h = getNodo(hijo);
            a->hijos.push_back(h);
        }
    }

    for (auto &[_, nodo] : grafo)
        for (int d = 0; d < 2; d++)
            for (int f = 0; f < 2; f++)
                dp[d][f][nodo] = -1;

    cout << dfs(getNodo("svr"), false, false);

    return 0;
}
