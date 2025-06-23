#include <bits/stdc++.h>
using namespace std;

string LCS(string a, string b, int n, int m) {
    // Step 1: Create the DP table
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 2: Backtrack to get the LCS string
    int i = n, j = m;
    string s = "";

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            s.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }

    // The string is built in reverse
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string a = "abcde";
    string b = "abfce";
    int n = a.size();
    int m = b.size();

    string lcs = LCS(a, b, n, m);
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
