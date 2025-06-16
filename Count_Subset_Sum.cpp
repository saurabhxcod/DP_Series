#include <iostream>
#include <vector>
using namespace std;

int countSubsets(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    // Initialize: number of ways to make sum 0 is 1 (empty subset)
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Build the table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    cout << "Count of subsets with sum " << sum << ": " << countSubsets(arr, sum) << endl;
    return 0;
}
