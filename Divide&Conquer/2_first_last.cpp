#include <bits/stdc++.h>
using namespace std;
int firstOccurence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}
int lastOccurence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int> &nums, int target)
{

    return {firstOccurence(nums, target), lastOccurence(nums, target)};
}
int main(int argc, char const *argv[])
{

    return 0;
}
