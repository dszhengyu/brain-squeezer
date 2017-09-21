#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;


bool isScramble(string s1, string s2);

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    cout << isScramble(s1, s2) << endl;
}

bool isScramble(string s1, string s2) {
    if (s1 == s2) {
        return true;
    }

    int len = s1.length();
    int count[26] = {0};
    for (int i = 0; i < len; ++i) {
        ++count[s1[i] - 'a'];
        --count[s2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] != 0) {
            return false;
        }
    }

    for (int i = 1; i < len; ++i) {
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
            return true;
        }
        if (isScramble(s1.substr(0, len - i), s2.substr(i)) && isScramble(s1.substr(len - i), s2.substr(0, i))) {
            return true;
        }
    }
    return false;
}

