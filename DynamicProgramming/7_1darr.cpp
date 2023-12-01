#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr)
{
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {

        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];

        dp[i] = max(pick, nonPick);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> arr{1, 2, 9, 4, 5, 0, 4, 11, 6};
    int n = arr.size();

    cout << solve(n, arr);

    return 0;
}
