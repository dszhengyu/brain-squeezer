#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

int numDecodings(string s);

int main()
{
    string s;
    cin >> s;
    cout << numDecodings(s) << endl;
}

int numDecodings(string s) {
    int len = s.length();
    if (len == 0) {
        return 0;
    }

    vector<int> dp(len + 1, 0);
    dp[0] = 1;
    if (s[0] != '0') {
        dp[1] = 1;
    }
    for (int i = 1; i < len; ++i) {
        int first = stoi(s.substr(i, 1));
        int second = stoi(s.substr(i - 1, 2));
        if (first >= 1 && first <= 9) {
            dp[i + 1] += dp[i];
        }
        if (second >= 10 && second <= 26) {
            dp[i + 1] += dp[i - 1];
        }
    }
    return dp[len];
}

