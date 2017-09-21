#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;


int numTrees(int n);

int main()
{
    int n;
    cin >> n;
    cout << numTrees(n) << endl;
}

int numTrees(int n) {
    if (n < 2) {
        return 1;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <=i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
