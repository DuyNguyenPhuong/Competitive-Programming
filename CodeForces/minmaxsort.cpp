#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
#include <math.h>
#include <climits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#define ll long long
#define ull unsigned long long int
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vin(x, v)     \
    for (auto &x : v) \
        cin >> x;
#define vout(x, v)   \
    for (auto x : v) \
        cout << x << " ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define forl for (int i = 0; i < n; i++)
#define loop(i, j, k) for (int i = j; i < k; i += 1)
#define rloop(i, j, k) for (int i = j; i >= k; i -= 1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MODD 998244353

#define isortarr(arr, n) sort(arr, arr + n)
#define dsortarr(arr, n) sort(arr, arr + n, greater<int>())
#define isortvect(v) sort(v.begin(), v.end())
#define dsortvect(v) sort(v.begin(), v.end(), greater<>());
#define isortstrng(str) sort(str.begin(), str.end())
#define dsortstrng(str) sort(str.begin(), str.end(), greater<char>())
#define ltransfr(str) transform(str.begin(), str.end(), str.begin(), ::tolower)
#define utransfr(str) transform(str.begin(), str.end(), str.begin(), ::toupper)
#define ct(x) cout << x
#define cn(x) cin >> x
#define deb(x) cout << #x << "=" << x << endl
#define debb(x, y) cout << #x << "=" << x << " , " << #y << "=" << y << endl
#define cp(t) \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;
// srand(time(0));
// x = rand()%XYZ
//  cout<<fixed<<setprecision(15)<<

int zero = 0;
// int gcd(int a, int b)
//{
//      if (b == 0)
//           return a;
//      return gcd(b, a % b);
// }
// int lcm(int a, int b) { return a * b / gcd(a, b); }
//
// ll GA[10000001];
// void prime()
//{
//      memset(GA, 0, 10000001);
//      GA[0] = GA[1] = 1;
//      for (ll i = 2; i < 10000001; i++)
//      {
//           if (GA[i] == 0)
//           {
//                for (ll j = i * i; j < 10000001; j = j + i)
//                     GA[j] = 1;
//           }
//      }
// }
//
//
// bool check_ps(ll n)
//{
//      int sq = sqrt(n);
//      if (n == (sq*sq)
//      {
//           return true;
//      }
//      else
//      {
//           return false;
//      }
// }
//

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cp(t)
    {
        int n;
        cin >> n;
        int ar[n];
        map<int, int> mpp;
        forl
        {
            cin >> ar[i];
            mpp[ar[i]] = i;
        }
        int mid1 = ((n + 1) / 2), mid2 = (n + 2) / 2;
        int ind1 = (mpp[mid1]), ind2 = mpp[mid2];
        int op = (n / 2);
        if (is_sorted(ar, ar + n))
        {
            cout << 0 << endl;
        }
        else
        {
            if (n % 2)
            {
                if (((mpp[mid1 - 1] < ind1) && (ind1 < mpp[mid1 + 1])))
                {
                    mid1--;
                    mid2++;
                    ind1 = mpp[mid1];
                    ind2 = mpp[mid2];
                }
                else
                {
                    cout << op << endl;
                    continue;
                }
            }

            {
                int prev1 = ind1, prev2 = ind2;
                while ((ind1 <= prev1) && (prev2 <= ind2) && (prev1 < prev2))
                {
                    prev1 = ind1;
                    prev2 = ind2;
                    op--;
                    mid1--;
                    mid2++;
                    ind1 = mpp[mid1];
                    ind2 = mpp[mid2];
                    if (mid1 == 0)
                    {
                        break;
                    }
                }
                cout << op << endl;
            }
        }
    }

    return 0;
}