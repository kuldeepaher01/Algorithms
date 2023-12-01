
#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int k)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (num[0] <= k)
    {
        dp[0][num[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
            {
                taken = dp[ind - 1][target - num[ind]];
            }

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][k];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}