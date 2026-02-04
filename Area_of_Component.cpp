#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> grid;
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y]);
}
int cmp_sz;
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cmp_sz++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj))
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string r;
        cin >> r;
        grid.push_back(r);
    }
    memset(vis, false, sizeof(vis));
    int ans = INT_MAX;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                cmp_sz = 0;
                dfs(i, j);
                ans = min(ans, cmp_sz);
                found = true;
            }
        }
    }
    if (found)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
