#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        // inversion condition met here
        else
        {
            temp.push_back(arr[right]);
            // all the elements in left are greater than the element in right
            // bcz left is already sorted
            count += (mid - left + 1);
            right++;
        }
    }
    // if elems left in the left side add all of them
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // if elems left in right side we add all of them
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // copy the temp to the main arr
    for (int i = low; i <= high; i++)
    {
        cout << temp[i - low] << endl;
        arr[i] = temp[i - low]; // i-low because temp is not relative with arr it could be for smaller sized array
    }
    return count;
}
int merge1(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1, count = 0;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            count += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }

    return count;
}
int invertCnt(vector<int> &nums, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += invertCnt(nums, low, mid);
    count += invertCnt(nums, mid + 1, high);
    count += merge1(nums, low, mid, high);
    return count;
}

int mS(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += mS(arr, low, mid);
    count += mS(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}
int m(vector<int> &a, int n)
{

    return mS(a, 0, n - 1);
}

int main(int argc, char const *argv[])
{
    vector<int> a = {2, 4, 3, 5, 1};
    int n = 5;
    int c = m(a, n);
    cout << "No. of Inversions: " << c << endl;
    return 0;
}
