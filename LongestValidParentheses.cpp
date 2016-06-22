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
int longest(const string &s);

void solution(istream &in, ostream &out) {
    string s;
    in >> s;

    int maxLength = longest(s);

    out << maxLength << endl;
//    return maxLength;
}

int longest(const string &s) {
    stack<size_t> respondPosition;
    vector<int> length(s.length(), -1);
    int max = 0;

    for (size_t position = 0; position != s.length(); ++position) {
        const char currentChar = s[position];
        if (currentChar == '(') {
            respondPosition.push(position);
        }
        else {
            if (!respondPosition.empty() && (s[respondPosition.top()] == '(')) {
                size_t previousPosition = respondPosition.top();
                respondPosition.pop();
                size_t lengthLength = 0;
                if (previousPosition && (length[previousPosition - 1] != -1)) {
                    lengthLength = length[previousPosition - 1];
                }
                int currentLength = position - previousPosition + 1 + lengthLength;
                length[position] = currentLength;
                max = (max > currentLength) ? max : currentLength;
            }
            else {
                respondPosition.push(position);
            }
        }
    }

    return max;
}
