#include <bits/stdc++.h>
using namespace std;
int findLcs(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> tab(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        tab[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        tab[0][i] = 0;
    }
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                tab[ind1][ind2] = 1 + tab[ind1 - 1][ind2 - 1];
            else
                tab[ind1][ind2] = max(tab[ind1 - 1][ind2], tab[ind1][ind2 - 1]);
        }
    }

    return tab[n][m];
}
int main(int argc, char const *argv[])
{
    string s1 = "acd";
    string s2 = "ced";
    cout << findLcs(s1, s2) << endl;
    return 0;
}
