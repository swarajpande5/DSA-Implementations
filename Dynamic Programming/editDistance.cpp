// Edit Distance: https://leetcode.com/problems/edit-distance/

// Recursive program
class RecursiveSolution
{
public:
    int minDistanceUtility(string word1, string word2, int m, int n)
    {
        // If word1 is empty, then insert all characters of second string into first
        if (m == 0)
            return n;

        // If second string is empty, the only option is to remove all characters from first string
        if (n == 0)
            return m;

        // If last two characters are same, we go for the remaining string
        if (word1[m - 1] == word2[n - 1])
            return minDistanceUtility(word1, word2, m - 1, n - 1);

        // If last two characters are not same, consider all three operations on last character of first string recursively
        return 1 + min({
                       minDistanceUtility(word1, word2, m, n - 1),    // Insertion
                       minDistanceUtility(word1, word2, m - 1, n),    // Removal
                       minDistanceUtility(word1, word2, m - 1, n - 1) // Replacement
                   });
    }

    int minDistance(string word1, string word2)
    {
        return minDistanceUtility(word1, word2, word1.size(), word2.size());
    }
};

// Top Down DP Solution
class TopDownDPSolution
{
    int dp[501][501];

public:
    TopDownDPSolution()
    {
        memset(dp, -1, sizeof(dp));
    }

    int minDistanceUtility(string word1, string word2, int m, int n)
    {
        if (n == 0)
            return m;
        if (m == 0)
            return n;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (word1[m - 1] == word2[n - 1])
        {
            if (dp[m - 1][n - 1] != -1)
                return dp[m][n] = dp[m - 1][n - 1];
            else
                return dp[m][n] = minDistanceUtility(word1, word2, m - 1, n - 1);
        }

        int edit1, edit2, edit3;

        if (dp[m - 1][n] != -1)
            edit1 = dp[m - 1][n];
        else
            edit1 = minDistanceUtility(word1, word2, m - 1, n);

        if (dp[m][n - 1] != -1)
            edit2 = dp[m][n - 1];
        else
            edit2 = minDistanceUtility(word1, word2, m, n - 1);

        if (dp[m - 1][n - 1] != -1)
            edit3 = dp[m - 1][n - 1];
        else
            edit3 = minDistanceUtility(word1, word2, m - 1, n - 1);

        return dp[m][n] = 1 + min({edit1, edit2, edit3});
    }

    int minDistance(string word1, string word2)
    {
        return minDistanceUtility(word1, word2, word1.size(), word2.size());
    }
};

// Bottom Up DP Solution
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        int dp[m + 1][n + 1];

        // Filling dp in bottom up fashion
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = j;

                else if (j == 0)
                    dp[i][j] = i;

                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }

        return dp[m][n];
    }
};