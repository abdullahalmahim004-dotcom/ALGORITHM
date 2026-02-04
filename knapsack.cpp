#include <bits/stdc++.h>
using namespace std;
int val[1005], wt[1005];
int knapsack(int i, int mx_wt)
{
    if(i<0||mx_wt<=0)
    {
        return 0;
    }
    if (wt[i] <= mx_wt)
    {   
        // 2 options
        // 1. bag a rakhbo,2. bag a rakhbo na
        int op1 = knapsack(i - 1, mx_wt - wt[i]) + val[i];
        int op2 = knapsack(i - 1, mx_wt);
        return max(op1, op2);
    }
    else
    {
        // 1 option
        // bag e rakhte parbo na
        return knapsack(i - 1, mx_wt);
    }
}
int main()
{
    int n, mx_wt;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cin >> mx_wt;
    cout<<knapsack(n - 1, mx_wt)<<endl;
    return 0;
}