#include <bits/stdc++.h>
using namespace std;

string LCP(string a, string b)
{
    int i = 0, j = 0;
    while (i < a.length() && j < b.length())
    {
        if (a[i] != b[j])
            break;
        else
        {
            i++;
            j++;
        }
    }
    return a.substr(0, i);
}

string divide(vector<string> str, int low, int high)
{
    if (low > high)
        return "";
    if (low == high)
        return str[low];
    int mid = (low + high) / 2;
    string a = divide(str, low, mid);
    string b = divide(str, mid + 1, high);

    return LCP(a, b);
}

int main(int argc, char const *argv[])
{
    vector<string> str = {"technique", "technician", "technology", "technical"};
    cout << "Longest common prefix is: " << divide(str, 0, str.size() - 1);
    return 0;
}
