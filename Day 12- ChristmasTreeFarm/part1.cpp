#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    vector<int> v(6, 0);
    int cont = 0;
    
    while(cont < 6)
    {
    	getline(cin, line);
    	
    	if(!line.empty())
    	{	
    		for(size_t i = 0; i < line.length(); i++)
    			if(line[i] == '#') 
    				v[cont]++;
    	}
		else
			cont++;
    }
    
    int ans = 0;
    cont = 0;
    while(getline(cin, line))
    {
    	stringstream ss(line);
    	string data;
    	int tot, n1, n2;
    	char basura;
    	
    	ss >> n1 >> basura >> n2 >> basura;
    	tot = n1*n2;
    	
    	int algo = 0;
    	while(ss >> data)
    	{
    		algo += stoi(data) * v[cont++];
    		cont %= 6;
    	}
    	
    	if(tot > algo)
    		ans++;
    }
    
    cout << ans;
    
    return 0;
}
