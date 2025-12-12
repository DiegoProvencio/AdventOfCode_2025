#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> grid;
	string line;
	int cont = 0;
	while (getline(cin, line)) 
	grid.push_back(line);
	
	int n = grid.size();
	int m = grid[0].size();
	
	queue<pair<int, int>> q;
	for (int j = 0; j < m; j++) 
	if (grid[0][j] == 'S') q.push({0, j});
	
	vector<vector<int>> visited(n, vector<int>(m, -1));
	
  	while (!q.empty()) 
	{
	    int currI = q.front().first;
	    int currJ = q.front().second;
	    q.pop();
	
		int newI = currI + 1;
		int newJ = currJ;

		if (newI >= 0 && newI < n && grid[newI][newJ] == '.') 
		{
			visited[newI][newJ] = 1;
			grid[newI][newJ] = '|';
			q.push({newI, newJ});
      	}
		else if(newI >= 0 && newI < n && grid[newI][newJ] == '^')
		{
			cont++;
			if(visited[newI][newJ+1] == -1 && grid[newI][newJ+1] == '.')
			{
				q.push({newI, newJ+1});
				visited[newI][newJ+1] = 1;
				grid[newI][newJ+1] = '|';
			}
      			
  			if(visited[newI][newJ-1] == -1 && grid[newI][newJ-1] == '.')
  			{
  				q.push({newI, newJ-1});
  				visited[newI][newJ-1] = 1;
  				grid[newI][newJ-1] = '|';
  			}	
		}
	}

	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << grid[i][j];
		cout << "\n";
	}*/
		
	cout << cont;

	return 0;
}