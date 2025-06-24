#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of LCS
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

// Function to calculate length of Shortest Common Supersequence
int shortestCommonSupersequenceLength(string s1, string s2) {
    int lcs = longestCommonSubsequence(s1, s2);
    return s1.length() + s2.length() - lcs;
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Length of Shortest Common Supersequence: " 
         << shortestCommonSupersequenceLength(s1, s2) << endl;
    return 0;
}
