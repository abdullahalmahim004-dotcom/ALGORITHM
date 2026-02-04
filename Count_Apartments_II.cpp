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

int dfs(int si, int sj)   
{
    vis[si][sj] = true;
    int room = 1; 
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj))
        {
            room += dfs(ci, cj);
        }
    }
    return room;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        grid.push_back(row);
    }
    memset(vis, false, sizeof(vis));
    vector<int> ap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int room = dfs(i, j); 
                ap.push_back(room);
            }
        }
    }
    if (ap.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        sort(ap.begin(), ap.end());
        for (int i = 0; i < (int)ap.size(); i++)
        {
            cout << ap[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
