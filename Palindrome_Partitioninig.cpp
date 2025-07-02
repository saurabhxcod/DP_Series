#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int minCuts(string &s, int i, int j) {
    if (i >= j || isPalindrome(s, i, j))
        return 0;

    int minCost = INT_MAX;

    for (int k = i; k < j; ++k) {
        if (isPalindrome(s, i, k)) {
            int cost = 1 + minCuts(s, k + 1, j); 
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}

int main() {
    string s = "nitin";
    int i = 0, j = s.length() - 1;
    cout << "Minimum partition is: " << minCuts(s, i, j) << endl;
    return 0;
}

//Bottom Up Approach(Memoziation + Recursion)

class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i, int j, vector<int> &dp) {
        if (i >= j || isPalindrome(s, i, j)) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for (int k = i; k < j; ++k) {
            if (isPalindrome(s, i, k)) {
                int temp = 1 + solve(s, k + 1, j, dp);
                ans = min(ans, temp);
            }
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1); // dp[i] stores min cuts for s[i..n-1]
        return solve(s, 0, n - 1, dp);
    }
};

