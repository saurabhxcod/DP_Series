#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lcs(string a, string b) {
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    pair<int, int> minInsertDelete(string a, string b) {
        int lcs_len = lcs(a, b);
        int deletions = a.length() - lcs_len;
        int insertions = b.length() - lcs_len;
        return {insertions, deletions};
    }
};

int main() {
    Solution sol;
    string a = "heap";
    string b = "pea";

    auto [insertions, deletions] = sol.minInsertDelete(a, b);
    cout << "Minimum Insertions: " << insertions << endl;
    cout << "Minimum Deletions: " << deletions << endl;

    return 0;
}
