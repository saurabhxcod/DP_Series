#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int result = 0; // To store length of the longest common substring

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    result = max(result, dp[i][j]); // Update max length
                } else {
                    dp[i][j] = 0; // Reset if characters don't match
                }
            }
        }

        return result;
    }
};

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    Solution sol;
    int length = sol.longestCommonSubstr(s1, s2);

    cout << "Length of Longest Common Substring: " << length << endl;

    return 0;
}
