#include <bits/stdc++.h>
using namespace std;

string toggle(const string& s, const string& boton)
{
    string r = s;
    for (char c : boton)
    {
        int pos = c - '0';
        if (r[pos] == '.')
            r[pos] = '#';
        else
            r[pos] = '.';
    }
    return r;
}

int bfs(const string& estado, const vector<string>& boton)
{
    string start(estado.length(), '.'); 

    queue<pair<string,int>> q;
    unordered_set<string> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty())
    {
        auto [curr, dist] = q.front();
        q.pop();

        if (curr == estado)
            return dist;

        for (const string& b : boton)
        {
            string nxt = toggle(curr, b);

            if (!visited.count(nxt))
            {
                visited.insert(nxt);
                q.push({nxt, dist + 1});
            }
        }
    }

    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string estado, line;
    int total = 0; 
    
    while (getline(cin, line))
    {
        stringstream ss(line);
        vector<string> boton;
        
        ss >> estado;
        estado = estado.substr(1, estado.length() - 2);
        
        string l;
        while (ss >> l)
        {
            if (l[0] == '{')
                break;

            l = l.substr(1, l.size() - 2);

            string num = "";
            
            for (int i = 0; i <= (int)l.length() - 1; i += 2)
                num += l[i];

            boton.push_back(num);
        }

        int presses = bfs(estado, boton);
        total += presses;
    }

    cout << total << "\n";

    return 0;
}
