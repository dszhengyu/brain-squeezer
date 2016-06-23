#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solution(istream &in, ostream &out);

int main()
{
    solution(cin, cout); 
}

/************************************ Let's Start ********************************************/

bool isMatch(string s, string p);

void solution(istream &in, ostream &out) {
    string s;
    string p;

    in >> s >> p;
    
    bool result = isMatch(s, p);

    if (result) {
        out << "true" << endl;
    }
    else {
        out << "false" << endl;
    }
}

bool isMatch(string s, string p) {
    int sLength = s.length();
    int pLength = p.length();

    //result[i][j] means s[0, i - 1] match p[0, j - 1] or not
    //because a string of length n have n + 1 possible combination, so initialization plussed 1
    vector<vector<bool>> result(sLength + 1, vector<bool>(pLength + 1, false));

    result[0][0] = true;
    
    for (int j = 1; j <= pLength; ++j) {
        result[0][j] = (result[0][j - 1]) && (p[j - 1] == '*');
    }

    for (int i = 1; i <= sLength; ++i) {
        for (int j = 1; j <= pLength; ++j) {
            if (p[j - 1] == '*') {
                result[i][j] = result[i][j - 1] || result[i - 1][j] ;
            }
            else {
                result[i][j] = result[i - 1][j - 1] && ((p[j - 1] == s[i - 1]) || (p[j - 1] == '?'));
            }
        }
    }

    return result[sLength][pLength];
}
