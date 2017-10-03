#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if ((s1.length() + s2.length()) != s3.length()) {
        return false;
    }
    size_t m = s1.length() + 1;
    size_t n = s2.length() + 1;
    bool dp[m][n];

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;
    for (size_t i = 1; i < m; ++i) {
        if (s1[i - 1] != s3[i - 1]) {
            break;
        }
        dp[i][0] = true;
    }

    for (size_t j = 1; j < n; ++j) {
        if (s2[j - 1] != s3[j - 1]) {
            break;
        }
        dp[0][j] = true;
    }

    for (size_t i = 1; i < m; ++i) {
        for (size_t j = 1; j < n; ++j) {
            if (((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]) || 
                ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1])) {
                    dp[i][j] = true;
                }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << isInterleave(s1, s2, s3) << endl;
}
