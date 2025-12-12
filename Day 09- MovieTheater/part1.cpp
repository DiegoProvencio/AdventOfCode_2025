#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<long long, long long>> points;
    string line;

    while (getline(cin, line))
    {
        size_t c = line.find(',');

        long long x = stoll(line.substr(0, c));
        long long y = stoll(line.substr(c + 1));

        points.push_back({x, y});
    }
    
    long long max = 0;
    for(size_t i = 0; i < points.size(); i++)
    {
    	for(size_t j = i+1; j < points.size(); j++)
    	{
    		long long area = (abs(points[i].first - points[j].first) + 1)
    						* (abs(points[i].second - points[j].second + 1));
			if(area > max)
				max = area;
    	}
    }
	
	cout << max;

    return 0;
}