#include <bits/stdc++.h>
using namespace std;

long long concad(long long x) 
{
    string s = to_string(x);
    return stoll(s + s);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);

    long long total = 0;

    vector<string> ranges;
    size_t start = 0;

    while (true) 
    {
        size_t pos = line.find(',', start);
        if (pos == string::npos) {
            ranges.push_back(line.substr(start));
            break;
        }
        ranges.push_back(line.substr(start, pos - start));
        start = pos + 1;
    }

    for (string token : ranges) 
    {
        if (token.empty()) continue;

        size_t dash = token.find('-');
        long long A = stoll(token.substr(0, dash));
        long long B = stoll(token.substr(dash + 1));

        int lenA = to_string(A).size();
        int lenB = to_string(B).size();
    
        for (int L = lenA; L <= lenB; L++) 
        {

            if (L % 2 != 0) continue;
            int k = L / 2;

            long long startS = pow(10LL, k - 1);
            long long endS   = pow(10LL, k) - 1;

            for (long long S = startS; S <= endS; S++) 
            {
                long long N = concad(S);

                if (N < A) continue;  
                if (N > B) break;     

                total += N;         
            }
        }
    }

    cout << total << "\n";
    return 0;
}
