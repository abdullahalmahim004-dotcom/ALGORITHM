#include <bits/stdc++.h>
using namespace std;
int dp[100000];
bool rec(long long int n)
{
    if (1 == n)
    {
        return true;
    }
    else if (n == 0)
    {
        return false;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    bool l = false, r = false;
    if (n % 2 == 0)
    {
        l = rec(n / 2);
    }
    if (n >= 3)
    {
        r = rec(n - 3);
    }
    dp[n] = l || r;
    return dp[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        long long int n;
        cin >> n;
        if (rec(n))
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