#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    long long pos = 50;
    long long cont = 0;

    while (cin >> s) {
        long long num = stoll(s.substr(1));

        if (s[0] == 'R')
            pos = (pos + num) % 100;
        else
            pos = (pos - num + 10000) % 100;

        if (pos == 0) cont++;
    }

    cout << cont << endl;
}
