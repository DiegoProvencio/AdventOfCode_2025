#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	string num, line;
	vector<stringstream> v;
	int tot = 0;
	
	while(tot < 5)
	{
		int cont = 1;
		cin >> num;
		line = num;
		
		while(cont != 1000)
		{
			cin >> num;
			line = line + " " + num;
			
			cont++;
		}
		
		v.emplace_back(line);
		line = "";
		tot++;
	}
	
	vector<long long> suma(1000, 0);
	char x;
	long long a, b, c, d;
	for(long long i = 0; i < 1000; i++)
	{
		
		v[4] >> x;
		v[0] >> a; v[1] >> b; v[2] >> c; v[3] >> d;
		
		if(x == '+')
			suma[i] = a + b + c + d;
		else if(x == '*')
			suma[i] = a * b * c * d;
	}
	
	long long final = 0;
	for(long long i = 0; i < 1000; i++)
		final += suma[i];
	
	cout << final;
	
    return 0;
}