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
