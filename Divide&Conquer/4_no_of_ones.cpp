#include <bits/stdc++.h>
using namespace std;
int onesCount(vector<int> &nums, int n)
{
    int low = 0, high = n - 1, ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == 0)
        {
            low = mid + 1;
        }
        else
        {
            ans = n - mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 0, 0, 0, 1, 1, 1};
    cout << "No. of ones in array are: " << onesCount(nums, nums.size()) << endl;
    return 0;
}
