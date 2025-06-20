#include <iostream>
#include <vector>
using namespace std;

int rodCutting(int n, vector<int> &price) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<int> len(n); // lengths of the pieces

    for (int i = 0; i < n; i++) len[i] = i + 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (len[i - 1] <= j) {
                dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}

int main() {
    int n = 8;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << "Maximum profit: " << rodCutting(n, price) << endl;

    return 0;
}
