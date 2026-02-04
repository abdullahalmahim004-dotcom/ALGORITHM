#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool vis[1005][1005];
bool valid_path; 
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y]);
}
void dfs(int si, int sj, int di, int dj)
{
    vis[si][sj] = true;
    if (si == di && sj == dj) 
    {
        valid_path = true;
    }
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj))
        {
            dfs(ci, cj, di, dj);
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
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    memset(vis, false, sizeof(vis));
    valid_path = false;
    if (grid[si][sj] == '.' && grid[di][dj] == '.')
    {
        dfs(si, sj, di, dj);
    }
    if (valid_path)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
