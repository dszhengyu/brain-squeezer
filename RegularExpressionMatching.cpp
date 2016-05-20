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
    if (p.empty()) {
        return s.empty();
    }

    if (p[1] == '*') {
        return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p);
    }
    else {
        return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
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

