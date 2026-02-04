#include <bits/stdc++.h>
using namespace std;
int val[1005], wt[1005];
int dp[1005] [1005];
int knapsack(int i, int mx_wt)
{
    if (i < 0 || mx_wt <= 0)
    {
        return 0;
    }
    if(dp[i][mx_wt]!=-1)
    {
        return dp[i][mx_wt];
    }
    if (wt[i] <= mx_wt)
    {
        // 2 options
        // 1. bag a rakhbo,2. bag a rakhbo na
        int op1 = knapsack(i - 1, mx_wt - wt[i]) + val[i];
        int op2 = knapsack(i - 1, mx_wt);
        dp[i][mx_wt]= max(op1, op2);
        return dp[i][mx_wt];
    }
    else
    {
        // 1 option
        // bag e rakhte parbo na
        dp[i][mx_wt] =knapsack(i - 1, mx_wt);
        return dp[i][mx_wt];
    }
}
int main()
{
    int n, mx_wt;
    cin >> n;
    cin >> mx_wt;
    for (int i = 0; i < n; i++)
    {   
        cin >> wt[i];
        //cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {   
       // cin >> wt[i];
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= mx_wt; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n - 1, mx_wt) << endl;
    return 0;
}