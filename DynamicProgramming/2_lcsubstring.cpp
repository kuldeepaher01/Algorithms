#include <bits/stdc++.h>
using namespace std;
string findLcs(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> tab(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0;
    int endInd = m;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
            {
                int val = 1 + tab[ind1 - 1][ind2 - 1];
                tab[ind1][ind2] = val;
                if (tab[ind1][ind2] > maxLen)
                {
                    maxLen = tab[ind1][ind2];
                    endInd = ind1;
                }
            }
        }
    }
    return s1.substr(endInd - maxLen, maxLen);
}
int main(int argc, char const *argv[])
{
    string s1 = "abc";
    string s2 = "baba";
    cout << findLcs(s1, s2) << endl;
    return 0;
}
