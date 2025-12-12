#include <bits/stdc++.h>
using namespace std;

struct Nodo{
	string nombre;
	vector<Nodo*> hijos;
	
	Nodo() {}                       
    Nodo(const string& n) : nombre(n) {}   
};

unordered_map<string, Nodo*> grafo;

Nodo* getNodo(const string& nombre) 
{
    if (!grafo.count(nombre))
        grafo[nombre] = new Nodo(nombre);
    return grafo[nombre];
}

long long dfs(Nodo* u) 
{
    if (u->nombre == "out") return 1;

    long long total = 0;
    for (Nodo* v : u->hijos)
        total += dfs(v);
    return total;
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
    
    cout << dfs(getNodo("you"));

    return 0;
}