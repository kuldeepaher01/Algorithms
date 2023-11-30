#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumKadane(vector<int> &nums)
{
    int n = nums.size();
    int maxEndingHere = nums[0];
    int maxSoFar = nums[0];

    for (int i = 1; i < n; ++i)
    {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}
int maxSum(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return nums[low];
    int mid = (low + high) / 2;
    int l_max = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += nums[i];
        l_max = max(sum, l_max);
    }
    int r_max = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += nums[i];
        r_max = max(r_max, sum);
    }

    int l_r_max = max(maxSum(nums, low, mid), maxSum(nums, mid + 1, high));
    return max(l_r_max, l_max + r_max);
}

int main()
{
    vector<int> nums = {2, -4, 1, 9, -6, 7, -3};
    // int ans = maxSumKadane(nums);
    int ans = maxSum(nums, 0, nums.size() - 1);
    cout << "Max sum is: " << ans << endl;
    return 0;
}
