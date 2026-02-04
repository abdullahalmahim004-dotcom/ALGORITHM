#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
bool dfs(int src, int dst)
{
    if (src == dst)
    {
        return true;
    }
    for (int child : adj_list[src])
    {
        if (child == dst)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;

        if (dfs(src, dst))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
