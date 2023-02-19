#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;
#define cp(t)    \
    long long t; \
    cin >> t;    \
    while (t--)

int solve()
{
    long long n;
    cin >> n;

    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll x = 0;

    for (ll i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            x = max(x, (a[i] + a[i + 1] + 1) / 2);
        }
    }

    for (ll i = 0; i < n; i++)
    {
        a[i] = abs(a[i] - x);
    }

    for (ll i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            x = -1;
        }
    }

    cout << x << endl;

    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}