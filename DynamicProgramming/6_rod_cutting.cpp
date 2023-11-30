#include <bits/stdc++.h>
using namespace std;

int rodCut(vector<int> &nums, int n)
{
    vector<vector<int>> tab(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
    {
        tab[0][N] = N * nums[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= n; cap++)
        {
            int nottaken = tab[ind - 1][cap];
            int taken = INT_MIN;
            int rodL = ind + 1;
            if (rodL <= cap)
            {
                taken = nums[ind] + tab[ind][cap - rodL];
            }
            tab[ind][cap] = max(taken, nottaken);
        }
    }
    return tab[n - 1][n];
}

int main(int argc, char const *argv[])
{
    vector<int> rod = {2, 3, 4, 5, 10};
    int n = 5;
    cout << rodCut(rod, n) << endl;
    return 0;
}
