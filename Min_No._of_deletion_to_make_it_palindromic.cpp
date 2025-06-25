#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string a) {
        string b = a;
        reverse(b.begin(), b.end());
        int n = a.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // LCS between a and reverse(a)
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }

    int minDeletionsToPalindrome(string s) {
        int lpsLength = longestPalindromeSubseq(s);
        return s.size() - lpsLength;
    }
};

int main() {
    Solution sol;
    string s = "aebcbda";
    cout << "Minimum deletions to make palindrome: " << sol.minDeletionsToPalindrome(s) << endl;
    return 0;
}
