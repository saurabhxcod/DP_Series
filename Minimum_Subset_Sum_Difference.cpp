#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

int minSubsetSumDifference(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    
    vector<vector<bool>> dp(n+1, vector<bool>(totalSum+1, false));
    
    // Initialize
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    // DP table fill
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= totalSum; j++) {
            if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // Find minimum difference
    int minDiff = INT_MAX;
    for(int s1 = 0; s1 <= totalSum/2; s1++) {
        if(dp[n][s1]) {
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }
    
    return minDiff;
}

int main() {
    vector<int> nums = {1, 2, 7};
    cout << "Minimum Subset Sum Difference: " << minSubsetSumDifference(nums) << endl;
    return 0;
}
