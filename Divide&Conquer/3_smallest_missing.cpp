#include <bits/stdc++.h>
using namespace std;

int missingEle(vector<int> &nums, int low, int high)
{
    if (low > high)
    {
        return low;
    }

    int mid = (low + high) / 2;
    if (nums[mid] == mid)
    {
        return missingEle(nums, mid + 1, high);
    }
    else
    {
        return missingEle(nums, low, mid - 1);
    }
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 6, 9, 11, 15};
    cout << "The smallest missing element is: " << missingEle(nums, 0, nums.size() - 1) << endl;
    return 0;
}
