#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> grid;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<pair<int, int>> cur_path;
vector<pair<int, int>> best_path;
bool vis[1005][1005];
bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && (grid[x][y] == '.' || grid[x][y] == 'D');
}
void dfs(int x, int y, int di, int dj)
{
    vis[x][y] = true;
    cur_path.push_back({x, y});
    if (x == di && y == dj)
    {
        if (best_path.empty() || cur_path.size() < best_path.size())
        {
            best_path = cur_path;
        }
    }
    else
    {
        for (auto [dx, dy] : d)
        {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny))
            {
                dfs(nx, ny, di, dj);
            }
        }
    }
    cur_path.pop_back();
    vis[x][y] = false;
}
int main()
{
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    int si = -1, sj = -1, di = -1, dj = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(si, sj, di, dj);
    for (auto [x, y] : best_path)
    {
        if (grid[x][y] == '.')
        {
            grid[x][y] = 'X';
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << grid[i] << endl;
    }
    return 0;
}
