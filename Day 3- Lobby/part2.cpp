#include <bits/stdc++.h>
using namespace std;

string subcadena(const string& s) 
{
    int size = s.length();
    int tot = 12;         
    int ini = 0;          
    string num;

    for (int k = 1; k <= 12; k++) 
    {
        int limit = size - (tot);
        
        char max = '0';
        int pos = ini;

        for (size_t i = ini; i <= limit; i++) 
        {
            if (s[i] > max) 
            {
                max = s[i];
                pos = i;
                if (s[i] == '9') break;
            }
        }

        num += max;
        ini = pos + 1;
        tot--;
    }

    return num;
}

int main() 
{
    string line;
    long long tot = 0;

    while(getline(cin, line)) 
    {
        string r = subcadena(line);
        tot += stoll(r);
    }

    cout << tot << endl;
}
