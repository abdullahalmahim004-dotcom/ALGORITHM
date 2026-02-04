#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
vector<Edge> edge_list;
vector<int> q;
long long dis[1005];
int n, e, s, t;
void bellman_ford()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            long long c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        long long c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cout << "Negative Cycle Detected" << endl;
            return;
        }
    }
    for (int d : q)
    {
        if (dis[d] == LLONG_MAX)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[d] << endl;
        }
    }
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }
    cin >> s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }
    for (int i = 0; i < t; i++)
    {
        cin >> q[i];
    }
    bellman_ford();
    return 0;
}
