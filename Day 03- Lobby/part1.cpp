#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	string line, num;
	char max; 
	long long pos, tot = 0;
	
	while(getline(cin, line))
	{
		max = line[0];
		pos = 0;
		for (size_t i = 1; i < line.length(); i++)
		{
			if (line[i] > max)
			{
				if (i != line.length()-1)
				{
					max = line[i];	
					pos = i;
					
					if (line[i] == '9') break;
				}
			}
		}
		
		num += max;
		max = line[pos+1];
		for (size_t i = pos+2; i < line.length(); i++)
		{
			if (line[i] > max)
				max = line[i];
		}
		num += max;
		
		tot += stoi(num);
		num = "";
	}
	
	cout << tot << endl;
    	
    return 0;
}