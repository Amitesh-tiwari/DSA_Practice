Problem statement
Given a text and a wildcard pattern of size N and M respectively, implement a wildcard pattern matching algorithm that finds if the wildcard pattern is matched with the text. The matching should cover the entire text not partial text.

The wildcard pattern can include the characters ‘?’ and ‘*’

 ‘?’ – matches any single character 
 ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= 200

Where 'N' denotes the length of 'TEXT' and 'M' denotes the length of 'PATTERN'.

'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain special characters ‘*’ and ‘?’

Time Limit: 1sec

//code

bool wildcardMatching(string pattern, string text)
{
    int n = text.length();
    int m = pattern.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
    {
        if (pattern[i - 1] == '*')
        {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else if (pattern[j - 1] == '?' || pattern[j - 1] == text[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[n][m];
}