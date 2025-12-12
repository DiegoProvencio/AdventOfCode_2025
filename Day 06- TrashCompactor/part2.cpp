#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    string line;
    char x;
    vector<string> nums;
    vector<string> s;
    vector<stringstream> v;

    while(getline(cin, line))
    {
    	s.push_back(line);
    	v.emplace_back(line);
    }
    
	int max_len = max({ s[0].size(), s[1].size(), s[2].size(), s[3].size() });
    
    v[4] >> x;
    long long total = (x == '+') ? 0 : 1;
    long long final = 0;
    for(size_t i = 0; i < max_len; i++)
    {
    	if(s[0][i] == ' ' && s[1][i] == ' ' && s[2][i] == ' ' && s[3][i] == ' ')
    	{
    		v[4] >> x;
    		final += total;
    		total = (x == '+') ? 0 : 1;
    	}
    	else
    	{
	        string num = "";
	        
	        if(s[0][i] != ' ') num = num + s[0][i];
	        if(s[1][i] != ' ') num = num + s[1][i];
	        if(s[2][i] != ' ') num = num + s[2][i];
	        if(s[3][i] != ' ') num = num + s[3][i];
	        
	        long long n = stoll(num);
	        if(x == '+')
	            total = total + n;
	        else if(x == '*')
	            total = total * n;
    	}
    }
	
	final += total;
    cout << final;

    return 0;
}