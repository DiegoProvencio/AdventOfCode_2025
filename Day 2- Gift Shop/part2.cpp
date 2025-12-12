#include <bits/stdc++.h>
using namespace std;

bool esInvalido(long long N) 
{
    string s = to_string(N);
    int len = s.length();
    
    for (int k = 1; k <= len / 2; k++) 
    {
        if (len % k == 0) 
        {
            int reps = len / k;
            if (reps >= 2) 
            {
                string patron = s.substr(0, k);
                bool valido = true;
                
                for (int i = k; i < len; i += k) 
                {
                    if (s.substr(i, k) != patron) 
                    {
                        valido = false;
                        break;
                    }
                }
                
                if (valido) return true;
            }
        }
    }
    
    return false;
}

int main() {
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
        if (pos == string::npos) 
        {
            ranges.push_back(line.substr(start));
            break;
        }
        ranges.push_back(line.substr(start, pos - start));
        start = pos + 1;
    }
    
    for (string t : ranges) 
    {
        if (!t.empty()) 
        {
            size_t dash = t.find('-');
            long long A = stoll(t.substr(0, dash));
            long long B = stoll(t.substr(dash + 1));
            
            for (long long N = A; N <= B; N++)
            {
                if (esInvalido(N)) 
                {
                    total += N;
                }
            }
        }
    }
    
    cout << total << "\n";
    return 0;
}