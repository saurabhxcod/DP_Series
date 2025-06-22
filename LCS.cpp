//Recursive Approach
#include <iostream>
using namespace std;

int lcs(string X, string Y, int m, int n) {
    // Base Case: If either string is empty
    if (m == 0 || n == 0)
        return 0;

    // If characters match, move diagonally
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);

    // If characters don't match, take max of skipping one from either string
    else
        return max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    int m = X.length();
    int n = Y.length();

    cout << "Length of LCS is " << lcs(X, Y, m, n) << endl;

    return 0;
}


//memoization
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsHelper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    // Base case: if any index goes below 0
    if (i < 0 || j < 0) return 0;

    // If already computed
    if (dp[i][j] != -1) return dp[i][j];

    // If characters match
    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + lcsHelper(s1, s2, i - 1, j - 1, dp);
    } else {
        // Characters don't match
        return dp[i][j] = max(
            lcsHelper(s1, s2, i - 1, j, dp),
            lcsHelper(s1, s2, i, j - 1, dp)
        );
    }
}

int longestCommonSubsequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    // Initialize memoization table with -1
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcsHelper(s1, s2, n - 1, m - 1, dp);
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Length of LCS: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}


//Top-Down Code

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    
    // Create a dp table of size (n+1) x (m+1)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Build the table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Characters don't match
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Length of LCS: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}




