#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

int minDistance(string word1, string word2);

int main()
{
    string w1, w2;
    cin >> w1 >> w2;
    cout << minDistance(w1, w2) << endl;
}

int minDistance(string word1, string word2) {
    int w1Len = word1.length();
    int w2Len = word2.length();
    vector<vector<int>> dp(w2Len + 1, vector<int>(w1Len + 1, w1Len + w2Len));
    vector<bool> hasZeroCol(w1Len + 1, false);
    
    for (int i = 0; i < w2Len; ++i) {
        bool hasZero = false;
        for (int j = 0; j < w1Len; ++j) {
            if (hasZero || hasZeroCol[j]) {
                dp[i][j] = 1;
                continue;
            }
            if (word1[j] == word2[i]) {
                dp[i][j] = 0;
                hasZero = true;
                hasZeroCol[j] = true;
            }
            else {
                dp[i][j] = 1;
            }
        }
    }

    //cout << "mark zero" << endl;
    //for (int i = 0; i <= w2Len; ++i) {
    //    for (int j = 0; j <= w1Len; ++j) {
    //        printf("%2d ", dp[i][j]);
    //    }
    //    cout << endl;
    //}

    for (int i = (w2Len - 1); i >= 0; --i) {
        for (int j = (w1Len - 1); j >= 0; --j) {
            if ((i == (w2Len - 1)) && (j == (w1Len - 1))) {
                continue;
            }
            if (dp[i][j] == 0) {
                dp[i][j] += min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
            }
            else {
                dp[i][j] += min(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    //cout << "sum" << endl;
    //for (int i = 0; i <= w2Len; ++i) {
    //    for (int j = 0; j <= w1Len; ++j) {
    //        printf("%2d ", dp[i][j]);
    //    }
    //    cout << endl;
    //}

    //cout << "result" << endl;
    return dp[0][0];
}
