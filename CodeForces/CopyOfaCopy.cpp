#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include "../Programming Library/grid_iterator.cpp"
#define ll long long
using namespace std;
#define cp(t)    \
    long long t; \
    cin >> t;    \
    while (t--)

#define forn(i, n) for (int i = 0; i < int(n); i++)

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct op
{
    int t, x, y, i;
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<string>> a(k + 1, vector<string>(n));
    forn(z, k + 1) forn(i, n)
            cin >>
        a[z][i];

    vector<int> cnt(k + 1);

    forn(z, k + 1)
    {
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 1; j < m - 1; ++j)
            {
                bool ok = true;
                forn(t, 4)
                    ok &= a[z][i][j] != a[z][i + dx[t]][j + dy[t]];
                cnt[z] += ok;
            }
        }
    }

    vector<int> ord(k + 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&cnt](int x, int y)
         { return cnt[x] > cnt[y]; });

    vector<op> ops;
    forn(z, k)
    {
        forn(i, n) forn(j, m) if (a[ord[z]][i][j] != a[ord[z + 1]][i][j])
        {
            a[ord[z]][i][j] ^= '0' ^ '1';
            ops.push_back({1, i + 1, j + 1, -1});
        }
        ops.push_back({2, -1, -1, ord[z + 1] + 1});
    }

    cout << ord[0] + 1 << '\n';
    cout << ops.size() << '\n';
    for (auto it : ops)
    {
        cout << it.t << " ";
        if (it.t == 1)
            cout << it.x << " " << it.y << '\n';
        else
            cout << it.i << '\n';
    }
}