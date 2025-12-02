#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s;
    long long pos = 50, cont = 0;

    while (cin >> s)
    {
        long long num = stoll(s.substr(1));

        if (s[0] == 'R') 
        {
            for (long long i = 0; i < num; i++) 
            {
                pos = (pos + 1) % 100;
                if (pos == 0) cont++;
            }
        } 
        else // L
        {
            for (long long i = 0; i < num; i++) 
            {
                pos = (pos - 1 + 100) % 100;
                if (pos == 0) cont++;
            }
        }
    }

    cout << cont << endl;
    return 0;
}
