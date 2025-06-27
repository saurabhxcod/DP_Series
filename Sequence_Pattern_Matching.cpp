#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string a, string b) {
    int n = a.length();
    int m = b.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m] == n; 
}

int main() {
    string a = "abc";
    string b = "ahbgdc";

    if (isSubsequence(a, b))
        cout << "Yes, A is a subsequence of B" << endl;
    else
        cout << "No, A is not a subsequence of B" << endl;

    return 0;
}
