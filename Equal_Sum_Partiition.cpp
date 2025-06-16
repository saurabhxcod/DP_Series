#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

bool canPartition(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // If total sum is odd, can't be partitioned equally
    if (totalSum % 2 != 0) return false;

    int target = totalSum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Initialize: sum 0 is always possible
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // DP table filling
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> arr = {1, 5, 11, 5};
    if (canPartition(arr))
        cout << "Array can be partitioned into two subsets of equal sum." << endl;
    else
        cout << "Array cannot be partitioned into two subsets of equal sum." << endl;

    return 0;
}
