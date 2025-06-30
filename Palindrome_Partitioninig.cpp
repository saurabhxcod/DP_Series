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
