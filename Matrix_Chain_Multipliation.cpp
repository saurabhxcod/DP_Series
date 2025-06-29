//Recursive Code

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of multiplications
int matrixChainRec(int arr[], int i, int j) {
    // Base case: Only one matrix
    if (i == j) return 0;

    int mini = INT_MAX;

    // Try placing a bracket at every possible position between i and j
    for (int k = i; k < j; k++) {
        int cost = matrixChainRec(arr, i, k) + 
                   matrixChainRec(arr, k + 1, j) + 
                   arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, cost);
    }

    return mini;
}

int main() {
    int arr[] = {40, 20, 30, 10, 30}; // Example dimensions
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications: " 
         << matrixChainRec(arr, 1, n - 1) << endl;

    return 0;
}


//Memoization
#include <bits/stdc++.h>
using namespace std;

int matrixChainMemo(int arr[], int i, int j, vector<vector<int>>& dp) {
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = matrixChainMemo(arr, i, k, dp) +
                   matrixChainMemo(arr, k + 1, j, dp) +
                   arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

int matrixChainOrder(int arr[], int n) {
    // Create dp table initialized with -1
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return matrixChainMemo(arr, 1, n - 1, dp);
}

int main() {
    int arr[] = {40, 20, 30, 10, 30}; // Example
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications: "
         << matrixChainOrder(arr, n) << endl;

    return 0;
}

