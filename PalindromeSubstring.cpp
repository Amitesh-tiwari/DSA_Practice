Problem statement
You have been given a string ‘A’ consisting of lower case
 English letters. Your task is to find the length of the
  longest palindromic subsequence in ‘A’.

A subsequence is a sequence generated from a string after
 deleting some or no characters of the string without 
 changing the order of the remaining string characters. 
 (i.e. “ace” is a subsequence of “abcde” while “aec” is
  not).

A string is said to be palindrome if the reverse of 
the string is the same as the actual string. For example, 
“abba” is a palindrome, but “abbc” is not a palindrome.

//code

#include <bits/stdc++.h> 
int longestPalindromeSubsequence(string s)
{
    int n = s.length();
    string t = s;
    reverse(t.begin(), t.end());
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}