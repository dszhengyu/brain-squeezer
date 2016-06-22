#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void solution(istream &in, ostream &out);

int main()
{
    solution(cin, cout); 
}

/************************************ Let's Start ********************************************/

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> result(m + 1, vector<bool>(n + 1, false));
    result[0][0] = true;

    for (int i = 1; i <= m; ++i) {
        result[i][0] = false;
    }

    for (int j = 2; j <= n; ++j) {
        result[0][j] = ('*' == p[j - 1]) && result[0][j - 2]; 
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ('*' == p[j - 1]) {
                result[i][j] = result[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && result[i - 1][j];
            }
            else {
                result[i][j] = result[i - 1][j - 1] && (s[i - 1] == p [j - 1]) || ('.' == p[j - 1]);
            }
        }
    }

    return result[m][n];
}

void solution(istream &in, ostream &out) {
    string s;
    string p;
    in >> s;
    in >> p;

    bool result = isMatch(s, p);

    if (result) {
        out << "true" << endl;
    }
    else {
        out << "false" << endl;
    }

    return;
}

