#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    -------------LONGEST COMMMON SUBSEQUENCE ( LCS )
*/

// Recursion
int solve(string s, string t, int ind1, int ind2)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }

    if (s[ind1] == t[ind2])
        return 1 + solve(s, t, ind1 - 1, ind2 - 1);
    else
        return max(solve(s, t, ind1 - 1, ind2), solve(s, t, ind1, ind2 - 1));
}

// MemoIzation
int solve(string s, string t, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }

    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }

    if (s[ind1] == t[ind2])
    {
        return dp[ind1][ind2] = 1 + solve(s, t, ind1 - 1, ind2 - 1, dp);
    }
    else
    {
        return dp[ind1][ind2] = max(solve(s, t, ind1 - 1, ind2, dp), solve(s, t, ind1, ind2 - 1, dp));
    }
}

// Tabulation
int lcs(string s, string t)
{
    // Write your code here

    int ind1 = s.length() - 1;
    int ind2 = t.length() - 1;
    int ind = max(ind1, ind2);

    /*
    ------------ This is done without space Optimisation
        vector<vector<int>> dp(ind + 2, vector<int>(ind + 2, 0));

        for (int i = 0; i <= s.length(); i++)
        {
            dp[i][0] = 0;
        }
    */
    vector<int> prev(ind2 + 3, 0);
    for (int i = 0; i <= t.length(); i++)
    {
        prev[i] = 0;
    }

    for (int ind1 = 1; ind1 <= s.length(); ind1++)
    {
        vector<int> curr(t.length() + 1, 0);
        for (int ind2 = 1; ind2 <= t.length(); ind2++)
        {

            if (s[ind1 - 1] == t[ind2 - 1])
            {
                curr[ind2] = 1 + prev[ind2 - 1];
            }
            else
            {
                curr[ind2] = max(prev[ind2], curr[ind2 - 1]);
            }
        }
        prev = curr;
    }

    return prev[t.length()];
}