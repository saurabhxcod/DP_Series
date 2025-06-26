#include <iostream>
#include <vector>
using namespace std;

string shortestCommonSupersequence(string s1, string s2) {
    int n = s1.size(), m = s2.size();

    // Step 1: Compute LCS DP table
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Step 2: Backtrack to build SCS from LCS table
    int i = n, j = m;
    string scs = "";

    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            scs += s1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            scs += s1[i-1];
            i--;
        } else {
            scs += s2[j-1];
            j--;
        }
    }

    // Add remaining characters of s1 or s2
    while(i > 0){
        scs += s1[i-1];
        i--;
    }
    while(j > 0){
        scs += s2[j-1];
        j--;
    }

    // Since we built the string from end, reverse it
    reverse(scs.begin(), scs.end());

    return scs;
}

int main() {
    string s1 = "brute";
    string s2 = "groot";

    cout << "Shortest Common Supersequence: " << shortestCommonSupersequence(s1, s2) << endl;

    return 0;
}
