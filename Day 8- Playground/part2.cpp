#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

struct Edge
{
    long long dist;
    int u, v;

    bool operator<(const Edge& other) const 
    {
        return dist < other.dist;
    }
};

int main()
{
    vector<array<long long, 3>> points;
    string line;

    while (getline(cin, line))
    {
        size_t c1 = line.find(',');
        size_t c2 = line.find(',', c1 + 1);

        long long x = stoll(line.substr(0, c1));
        long long y = stoll(line.substr(c1 + 1, c2 - c1 - 1));
        long long z = stoll(line.substr(c2 + 1));

        points.push_back({x, y, z});
    }

    int n = points.size();
    parent.resize(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long dx = points[i][0] - points[j][0];
            long long dy = points[i][1] - points[j][1];
            long long dz = points[i][2] - points[j][2];

            long long d2 = dx*dx + dy*dy + dz*dz;

            edges.push_back({d2, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    int componentes = n;
    int last_u = -1, last_v = -1;

    for (auto &e : edges)
    {
        int ru = find_set(e.u);
        int rv = find_set(e.v);

        if (ru != rv) 
        {
            union_sets(ru, rv);
            componentes--;

            if (componentes == 1)
            {
                last_u = e.u;
                last_v = e.v;
                break;
            }
        }
    }

    long long x1 = points[last_u][0];
    long long x2 = points[last_v][0];
    long long result = x1 * x2;

    cout << result << endl;

    return 0;
}
