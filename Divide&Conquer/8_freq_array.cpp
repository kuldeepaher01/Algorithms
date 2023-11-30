#include <bits/stdc++.h>
using namespace std;

void findFreq(vector<int> &nums, int size)
{
    unordered_map<int, int> freq_mp;
    int low = 0, high = size - 1;
    while (low <= high)
    {
        if (nums[low] == nums[high])
        {
            freq_mp[nums[low]] += high - low + 1;
            low = high + 1;
            high = size - 1;
        }
        else
        {
            high = (low + high) / 2;
        }
    }
    for (auto pair : freq_mp)
    {
        cout << pair.first << " appears " << pair.second << " times." << endl;
    }
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9};
    findFreq(nums, nums.size());
    return 0;
}
