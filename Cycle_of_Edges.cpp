#include<bits/stdc++.h>
using namespace std;
int par[100005];
int sz[100005];
int find(int node) 
{
    if (par[node] == -1)
    {
        return node;
    }
    int leader = find(par[node]);
    {   
        par[node] = leader;
        return leader;
    }
}
void dsu_union(int node1,int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(sz[leader1] >= sz[leader2])
    {
        par[leader2] = leader1;
        sz[leader1] += sz[leader2];
    }
    else
    {
        par[leader1] = leader2;
        sz[leader2] += sz[leader1];
    }
}
int main ()
{   
    memset(par, -1, sizeof(par));
    for(int i=0;i<100005;i++) sz[i]=1;
    int n,e;
    cin >> n >> e;
    int cyclecnt = 0;  
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        int leader1 = find(a);
        int leader2 = find(b);

        if(leader1 == leader2)
        {
            cyclecnt++;   
        }
        else
        {
            dsu_union(a,b);
        }
    }
    cout << cyclecnt << endl;
    return 0;
}
