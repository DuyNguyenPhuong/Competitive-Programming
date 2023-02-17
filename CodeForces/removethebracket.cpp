#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <math.h>
#include <climits>
#include <list>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <utility>

#define cp(t) \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;

void solve()
{
    int n, s;

    cin >> n >> s;
    vector<int> vec(n, 0);
    for (auto &i : vec)
    {
        cin >> i;
    }

    vector<pair<int, int>> lowerX, higherX;

    for (int i = 0; i < n; i++)
    {
        if (vec[i] > s)
        {
            lowerX.push_back({vec[i] - s, s});
            higherX.push_back({s, vec[i] - s});
        }
        else
        {
            lowerX.push_back({0, vec[i]});
            higherX.push_back({vec[i], 0});
        }
    }

    int res = 0;
    vector<int> dpLowerX(n, 0), dpHigherX(n, 0);

    for (int i = 1; i < n; i++)
    {
        if (i == 1)
        {
            dpLowerX[i] = vec[0] * lowerX[i].first;
            dpHigherX[i] = vec[0] * higherX[i].first;
        }
        else if (i == n - 1)
        {
            dpLowerX[i] = min(dpLowerX[i - 1] + lowerX[i - 1].second * vec[n - 1], dpHigherX[i - 1] + higherX[i - 1].second * vec[n - 1]);
            dpHigherX[i] = min(dpLowerX[i - 1] + lowerX[i - 1].second * vec[n - 1], dpHigherX[i - 1] + higherX[i - 1].second * vec[n - 1]);
        }
        else
        {
            dpLowerX[i] = min(dpLowerX[i - 1] + lowerX[i - 1].second * lowerX[i].first, dpHigherX[i - 1] + higherX[i - 1].second * higherX[i].first);
            dpHigherX[i] = min(dpLowerX[i - 1] + lowerX[i - 1].second * higherX[i].first, dpHigherX[i - 1] + higherX[i - 1].second * higherX[i].first);
        }
    }

    cout << min(dpLowerX[n - 1], dpHigherX[n - 1]) << endl;
    return;
}

int main()
{
    cp(t)
    {
        solve();
    }
}