#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int countWays(string &expr, int i, int j, bool isTrue) {
        // Base case
        if (i > j) return 0;

        if (i == j) {
            if (isTrue) return expr[i] == 'T';
            else return expr[i] == 'F';
        }

        int ways = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {
            char op = expr[k];

            int lt = countWays(expr, i, k - 1, true);
            int lf = countWays(expr, i, k - 1, false);
            int rt = countWays(expr, k + 1, j, true);
            int rf = countWays(expr, k + 1, j, false);

            if (op == '&') {
                if (isTrue) ways += lt * rt;
                else ways += lt * rf + lf * rt + lf * rf;
            }
            else if (op == '|') {
                if (isTrue) ways += lt * rt + lt * rf + lf * rt;
                else ways += lf * rf;
            }
            else if (op == '^') {
                if (isTrue) ways += lt * rf + lf * rt;
                else ways += lt * rt + lf * rf;
            }
        }

        return ways;
    }

    int countWaysToEvaluate(string expr) {
        return countWays(expr, 0, expr.size() - 1, true);
    }
};

int main() {
    Solution s;
    string expr = "T|F&T^T";
    cout << s.countWaysToEvaluate(expr) << endl;
}



//Bottom Up approach
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> mp;
const int MOD = 1003;

class Solution {
public:
    int countWays(string &expr, int i, int j, bool isTrue) {
        if (i > j) return 0;

        if (i == j) {
            if (isTrue) return expr[i] == 'T';
            else return expr[i] == 'F';
        }

        string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if (mp.find(key) != mp.end()) return mp[key];

        int ways = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {
            char op = expr[k];

            int lt = countWays(expr, i, k - 1, true);
            int lf = countWays(expr, i, k - 1, false);
            int rt = countWays(expr, k + 1, j, true);
            int rf = countWays(expr, k + 1, j, false);

            if (op == '&') {
                if (isTrue)
                    ways = (ways + (lt * rt) % MOD) % MOD;
                else
                    ways = (ways + (lt * rf) % MOD + (lf * rt) % MOD + (lf * rf) % MOD) % MOD;
            }
            else if (op == '|') {
                if (isTrue)
                    ways = (ways + (lt * rt) % MOD + (lt * rf) % MOD + (lf * rt) % MOD) % MOD;
                else
                    ways = (ways + (lf * rf) % MOD) % MOD;
            }
            else if (op == '^') {
                if (isTrue)
                    ways = (ways + (lt * rf) % MOD + (lf * rt) % MOD) % MOD;
                else
                    ways = (ways + (lt * rt) % MOD + (lf * rf) % MOD) % MOD;
            }
        }

        mp[key] = ways;
        return ways;
    }

    int countWaysToEvaluate(string expr) {
        mp.clear();  // Clear memoization map for fresh evaluation
        return countWays(expr, 0, expr.size() - 1, true);
    }
};

int main() {
    Solution s;
    string expr = "T|F&T^T";
    cout << "Number of ways: " << s.countWaysToEvaluate(expr) << endl;
    return 0;
}
