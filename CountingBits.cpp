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

void solution(istream &in, ostream &out) {

    int n;
    in >> n;

    vector<int> countingBits(n + 1);
    countingBits[0] = 0;
    for (int number = 1; number <= n; ++number) {
        if (number % 2) {
            countingBits[number] = countingBits[number - 1] + 1;
        }
        else {
            countingBits[number] = countingBits[number / 2];
        }
    }

    for (int ones : countingBits) {
        out << ones << ',';
    }
    out << endl;
}
