#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define cp(t) \
    int t;    \
    cin >> t; \
    while (t--)

string solve()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    for (int i = 0; i < 4; i++)
    {
        if (a1 < a2 && a2 < a4 && a1 < a3 && a3 < a4)
        {
            return "YES\n";
        }
        else if (a2 < a1 && a1 < a3 && a2 < a4 && a4 < a3)
        {
            return "YES\n";
        }
        else if (a3 < a1 && a1 < a2 && a3 < a4 && a4 < a2)
        {
            return "YES\n";
        }
        else if (a4 < a3 && a3 < a1 && a4 < a3 && a3 < a1)
        {
            return "YES\n";
        }
        return "NO\n";
    }
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