#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <tuple>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> board(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> board[i];
    }

    unordered_map<tuple<int, int>, int> visited;
    list<tuple<int, int>> queue;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'X')
            {
                queue.push_back(make_tuple(i, j));
                visited.insert({make_tuple(i, j), false});
            }
        }
    }

    for (int i = 0; i < queue.size(); i++)
    {
        cout << std::get<0>(queue.front());
    }
}
