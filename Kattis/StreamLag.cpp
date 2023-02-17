#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> P;
    // P.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int time, package;
        cin >> time >> package;
        P.emplace_back(package, time);
    }
    sort(P.begin(), P.end());

    long long timeLag = 0;
    unsigned int expectedTime = 1;
    for (auto [package, time] : P)
    {
        if (time <= expectedTime)
        {
            ++expectedTime;
            continue;
        }
        timeLag += time - expectedTime;
        expectedTime = time + 1;
    }
    cout << timeLag << endl;

    return 0;
}