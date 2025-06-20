#include <iostream>
#include <vector>
using namespace std;

int countWays(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base Case: There is 1 way to make amount 0 (pick nothing)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Build the table (Unbounded Knapsack - Complete Pack)
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Maximum number of ways to make amount " << amount << ": " << countWays(coins, amount) << endl;
    return 0;
}
