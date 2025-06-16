#include <iostream>
#include <vector>
using namespace std;

int countSubsetSumWithGivenDiff(vector<int>& arr, int diff) {
    int n = arr.size();
    int totalSum = 0;
    for (int num : arr) totalSum += num;
    if ((totalSum + diff) % 2 != 0) return 0; 
    int target = (totalSum + diff) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    // Initialization: there's 1 way to get sum 0 (empty subset)
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    cout << "Count of subsets with given difference: " 
         << countSubsetSumWithGivenDiff(arr, diff) << endl;
    return 0;
}
