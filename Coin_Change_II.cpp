//minimum number of coins

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));

    // Base Case: Zero amount requires 0 coins
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    // Initialize first row (except 0th column) with large value
    for (int j = 1; j <= amount; j++) {
        dp[0][j] = INT_MAX - 1; // Large number to avoid overflow in addition
    }

    // Build the table (Unbounded Knapsack - Min coins)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j)
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = minCoins(coins, amount);

    if (result != -1)
        cout << "Minimum number of coins to make amount " << amount << ": " << result << endl;
    else
        cout << "It's not possible to make amount " << amount << " with given coins." << endl;

    return 0;
}
