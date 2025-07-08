class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        int n = s1.length();

        // Base case: if both strings have different character frequency
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return false;

        // Try all possible partitions
        for (int i = 1; i < n; i++) {
            // Case 1: no swap
            if (
                isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))
            ) return true;

            // Case 2: swap
            if (
                isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))
            ) return true;
        }

        return false;
    }
};




//Bottom-Up Memoization
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> mp;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;

        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end()) return mp[key];

        // Quick check to prune unmatchable cases
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return mp[key] = false;

        int n = s1.size();
        for (int i = 1; i < n; i++) {
            // No swap case
            if (
                isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))
            ) return mp[key] = true;

            // Swap case
            if (
                isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))
            ) return mp[key] = true;
        }

        return mp[key] = false;
    }
};
