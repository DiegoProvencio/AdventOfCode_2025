#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	string line;
	vector<unsigned long long> v;
	unsigned long long num;
	int cont = 0;
	
	while(getline(cin, line))
	{
		if(line.empty()) break;
		
		int pos = line.find("-");
		v.push_back(stoll(line.substr(0, pos)));
		v.push_back(stoll(line.substr(pos + 1)));
	}
	
	while(cin >> num)
	{
		for(size_t i = 0; i < v.size(); i += 2)
		{
			if(num >= v[i] && num <= v[i+1])
			{
				cont++;
				break;
			}
		}
	}

	cout << cont;
    	
    return 0;
}