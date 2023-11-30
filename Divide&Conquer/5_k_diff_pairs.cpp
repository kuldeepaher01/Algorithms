#include <bits/stdc++.h>
using namespace std;

void pairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0, j = 0, size = nums.size();
    while (i < size && j < size)
    {
        while (i < size - 1 && nums[i] == nums[i + 1])
        {
            i++;
        }
        while (j < size - 1 && nums[j] == nums[j + 1])
        {
            j++;
        }
        if (nums[j] - nums[i] > k)
            i++;
        else if (nums[j] - nums[i] < k)
            j++;
        else
        {
            cout << "(" << nums[i] << "," << nums[j] << ") , ";
            i++;
            j++;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 5, 2, 2, 2, 5, 5, 4};
    int k = 3;
    pairs(nums, k);

    return 0;
}
