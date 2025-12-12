#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> grid;
    string line;
    while (getline(cin, line))
        grid.push_back(line);

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<ll>> ways(n, vector<ll>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int j = 0; j < m; j++)
        if (grid[0][j] == 'S') 
        {
            q.push({0, j});
            visited[0][j] = true;
            ways[0][j] = 1;
        }

    while (!q.empty())
    {
        int currI = q.front().first;
        int currJ = q.front().second;
        q.pop();

        int newI = currI + 1;
        int newJ = currJ;

        if (newI >= 0 && newI < n && grid[newI][newJ] == '.')
        {
            if (!visited[newI][newJ]) 
            {
                q.push({newI, newJ});
                visited[newI][newJ] = true;
            }
            ways[newI][newJ] += ways[currI][currJ];
        }
        else if(newI >= 0 && newI < n && grid[newI][newJ] == '^')
        {
            if (!visited[newI][newJ+1]) 
            {
                q.push({newI, newJ+1});
                visited[newI][newJ+1] = true;
            }
            ways[newI][newJ + 1] += ways[currI][currJ];

            if (!visited[newI][newJ-1]) 
            {
                q.push({newI, newJ-1});
                visited[newI][newJ-1] = true;
            }
            ways[newI][newJ - 1] += ways[currI][currJ];
        }
    }

    ll cont = 0;
    for (int j = 0; j < m; j++)
        cont += ways[n - 1][j];

    cout << cont << endl;

    return 0;
}