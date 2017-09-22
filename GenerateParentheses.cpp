#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

void generateHelper(vector<string> &ret, string str, int open, int close, int max) {
    if ((int)str.length() == max * 2) {
        ret.push_back(str);
        return;
    }
    if (open < max) {
        generateHelper(ret, str + "(", open + 1, close, max);
    }
    if (close < open) {
        generateHelper(ret, str + ")", open, close + 1, max);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    generateHelper(ret, string(), 0, 0, n);
    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<string> list = generateParenthesis(n);
    for (auto s  = list.begin(); s != list.end(); ++s) {
        cout << *s << endl;
    }
}
