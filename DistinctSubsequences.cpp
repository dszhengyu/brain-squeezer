#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;
int numDistinct(string s, string t) {
    size_t m = t.length() + 1;
    size_t n = s.length() + 1;

    int dp[m][n];
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            dp[i][j] = 0;
        }
    }
    for (size_t j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }
                
    for (size_t i = 1; i < m; ++i) {
        for (size_t j = 1; j < n; ++j) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << numDistinct(s, t) << endl;
}
