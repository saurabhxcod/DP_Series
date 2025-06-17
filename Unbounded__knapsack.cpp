#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int unboundedKnapsack(int n, int W, vector<int> &wt, vector<int> &val) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // i -> items (1 to n)
    // w -> capacity (0 to W)
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i][w - wt[i - 1]],  // take same item again
                    dp[i - 1][w]                         // don't take
                );
            } else {
                dp[i][w] = dp[i - 1][w]; // skip the item
            }
        }
    }

    return dp[n][W];
}

int main() {
    // Example input
    vector<int> wt = {2, 4, 6};       // weights
    vector<int> val = {5, 11, 13};    // corresponding values
    int W = 10;                       // knapsack capacity
    int n = wt.size();               // number of items

    int maxValue = unboundedKnapsack(n, W, wt, val);
    cout << "Maximum value in Unbounded Knapsack = " << maxValue << endl;

    return 0;
}
