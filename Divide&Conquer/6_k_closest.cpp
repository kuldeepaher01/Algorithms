#include <bits/stdc++.h>
using namespace std;

void findPairs(vector<int> &nums, int k, int target)
{
    int low = 0, high = nums.size();
    while (high - low >= k)
    {
        if (abs(nums[low] - target) > abs(nums[high] - target))
            low++;
        else
            high--;
    }
    while (low <= high)
    {
        cout << nums[low++] << ",";
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {10, 12, 15, 17, 18, 20, 25};
    int k = 4, target = 16;
    findPairs(nums, k, target);
    return 0;
}
