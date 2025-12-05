#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<pair<long long, long long>> v;
    string line;
    long long cont = 0;

    while (getline(cin, line)) 
    {
        if (line.empty()) break;

        int pos = line.find('-');
        long long a = stoll(line.substr(0, pos));
        long long b = stoll(line.substr(pos + 1));
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    vector<pair<long long, long long>> merged;

    for (auto &p : v) 
    {
        if (merged.empty() || p.first > merged.back().second) 
            merged.push_back(p);
        else 
            merged.back().second = max(merged.back().second, p.second);
    }

    for (auto &p : merged) 
    {
        cont += (p.second-p.first+1);
    }
    
    cout << cont;

    return 0;
}
