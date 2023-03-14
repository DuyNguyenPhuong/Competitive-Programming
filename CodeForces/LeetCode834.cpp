#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "../Programming Library/grid_iterator.cpp"
#define ll long long
using namespace std;
#define cp(t)    \
    long long t; \
    cin >> t;    \
    while (t--)

#define forn(i, n) for (int i = 0; i < int(n); i++)
class Solution
{
public:
    vector<unordered_set<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        tree.resize(n);
        res.assign(n, 0);
        count.assign(n, 1);

        for (auto e : edges)
        {
            tree[e[1]].insert(e[0]);
            tree[e[0]].insert(e[1]);
        }

        dfs(0, -1);
        dfs2(0, -1);
        return res;
    }
    // res distance of all node from substree of root i
    // root in substree of root i
    // Post order
    void dfs(int root, int pre)
    {
        for (auto i : tree[root])
        {
            if (i == pre)
            {
                continue;
            }
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    // Preorder
    void dfs2(int root, int pre)
    {
        for (auto i : tree[root])
        {
            if (i == pre)
            {
                continue;
            }
            res[i] = res[root] - count[i] + (count.size() - count[i]);
            dfs2(i, root);
        }
    }
};