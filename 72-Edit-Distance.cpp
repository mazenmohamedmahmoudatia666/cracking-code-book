#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // Create a 2D DP array
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize the base cases
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i; // Deleting all characters from word1
        }
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = j; // Inserting all characters into word1
        }

        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // Characters match, no new operation needed
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1,   // Delete character from word1
                                    dp[i][j - 1] + 1,   // Insert character into word1
                                    dp[i - 1][j - 1] + 1}); // Replace character
                }
            }
        }

        // The answer is in dp[n][m]
        return dp[n][m];
    }
};


