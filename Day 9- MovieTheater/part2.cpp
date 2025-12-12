#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<long long, long long>> pts;
    long long x, y;
    char comma;

    while (cin >> x >> comma >> y) 
    {
        pts.push_back({x, y});
    }

    int n = (int)pts.size();
    long long best = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j) 
        {
            long long x1 = min(pts[i].first,  pts[j].first);
            long long x2 = max(pts[i].first,  pts[j].first);
            long long y1 = min(pts[i].second, pts[j].second);
            long long y2 = max(pts[i].second, pts[j].second);

            long long area = (x2 - x1 + 1) * (y2 - y1 + 1);
            if (area <= best) continue;

            bool ok = true;

            for (int k = 0; k < n; ++k) 
            {
                long long ax = pts[k].first;
                long long ay = pts[k].second;
                long long bx = pts[(k + 1) % n].first;
                long long by = pts[(k + 1) % n].second;

                long long lx1 = min(ax, bx);
                long long lx2 = max(ax, bx);
                long long ly1 = min(ay, by);
                long long ly2 = max(ay, by);

                bool fuera =
                    (lx2 <= x1) ||  
                    (lx1 >= x2) ||  
                    (ly2 <= y1) ||  
                    (ly1 >= y2);    


                if (!fuera) 
                {
                    ok = false;
                    break;
                }
            }

            if (ok) 
                best = area;
        }
    }

    cout << best << "\n";
    return 0;
}
