#include <iostream>
#include <climits>
using namespace std;

int eggDrop(int e, int f) {
    // Base cases
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;

    int minAttempts = INT_MAX;

    // Try dropping from each floor
    for (int k = 1; k <= f; ++k) {
        int breakCase = eggDrop(e - 1, k - 1); // Egg breaks
        int noBreakCase = eggDrop(e, f - k);   // Egg doesn't break
        int worstCase = 1 + max(breakCase, noBreakCase);

        minAttempts = min(minAttempts, worstCase);
    }

    return minAttempts;
}

int main() {
    int eggs = 2, floors = 10;
    cout << "Minimum number of attempts in worst case: " << eggDrop(eggs, floors);
    return 0;
}


//Bottom Up / Memoization
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int eggDrop(int e, int f, vector<vector<int>>& dp) {
    // Base cases
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;

    // Check if already computed
    if (dp[e][f] != -1)
        return dp[e][f];

    int minAttempts = INT_MAX;

    // Try all floors
    for (int k = 1; k <= f; ++k) {
        int breakCase, noBreakCase;

        // Check if already computed to avoid recomputation
        if (dp[e - 1][k - 1] != -1)
            breakCase = dp[e - 1][k - 1];
        else {
            breakCase = eggDrop(e - 1, k - 1, dp);
            dp[e - 1][k - 1] = breakCase;
        }

        if (dp[e][f - k] != -1)
            noBreakCase = dp[e][f - k];
        else {
            noBreakCase = eggDrop(e, f - k, dp);
            dp[e][f - k] = noBreakCase;
        }

        int worstCase = 1 + max(breakCase, noBreakCase);
        minAttempts = min(minAttempts, worstCase);
    }

    return dp[e][f] = minAttempts;
}

int main() {
    int eggs = 2, floors = 10;
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, -1));

    cout << "Minimum number of attempts in worst case: " << eggDrop(eggs, floors, dp);
    return 0;
}
