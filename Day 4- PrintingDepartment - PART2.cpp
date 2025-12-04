#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	string line;
	vector<string> map;
	int cont = 0;
	bool can_remove = true;
	
	while(getline(cin, line))
		map.push_back(line);
		
	int n = map.size();
	int m = map[0].size();
	
	vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},
									{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
	
	do
	{
		vector<vector<int>> pos(n, vector<int>(m, 0));
		can_remove = false;
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{		
				if(map[i][j] != '@')
					continue;
					
				for(auto [dI, dJ] : delta)
				{
					int newI = i + dI;
	     			int newJ = j + dJ;
	     			
	     			if (newI >= 0 && newI < n && newJ >= 0 && newJ < m 
					&& map[newI][newJ] == '@') 
					{
						pos[i][j] += 1; 
					}
				}
				
				if(pos[i][j] < 4) 
				{
					can_remove = true;
					map[i][j] = '.';
					cont++;	
				}
			}
		}		
	} while(can_remove);

	
	cout << cont;
    	
    return 0;
}