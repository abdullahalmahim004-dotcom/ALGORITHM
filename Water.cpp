#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        int first = 0;
        int second = 0;
        for (int i = 1; i < n; i++)
        {
            if (h[i] > h[first])
            {
                second = first;
                first = i;
            }
            else if (i != first && (second == first || h[i] > h[second]))
            {
                second = i;
            }
        }
        if (first > second)
        {
            swap(first, second);
        }
        cout << first << " " << second << endl;
    }
    return 0;
}
