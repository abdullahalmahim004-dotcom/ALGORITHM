#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (adj_list[x].empty())
        {
            cout << -1 << endl;
            continue;
        }
        sort(adj_list[x].rbegin(), adj_list[x].rend());
        for (int val : adj_list[x])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
