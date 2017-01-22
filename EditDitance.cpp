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

void output(string word1, string word2, vector<vector<int>> dp) {
    int w1Len = word1.length();
    int w2Len = word2.length();
    cout << "  ";
    for (int j = 0; j < w1Len; ++j) {
        cout << word1[j] << " ";
    }
    cout << endl;

    for (int i = 0; i < w2Len; ++i) {
        cout << word2[i] << " ";
        for (int j = 0; j < w1Len; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int minDistance(string word1, string word2) {
    int w1Len = word1.length();
    int w2Len = word2.length();
    if ((w1Len == 0) || (w2Len == 0)) {
        return w1Len + w2Len;
    }

    vector<int> dp(w1Len + 1, 0);
    for (int j = 0; j <= w1Len; ++j) {
        dp[j] = j;
    }

    for (int i = 1; i <= w2Len; ++i) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 0; j < w1Len; ++j) {
            int tmp = dp[j + 1];
            if (word2[i - 1] == word1[j]) {
                dp[j + 1] = prev;
            }
            else {
                dp[j + 1] = (1 + min(dp[j + 1], min(prev, dp[j])));
            }
            prev = tmp;
        }
    }

    return dp[w1Len];

}

