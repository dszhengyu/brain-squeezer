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
    cout << minDistance(w1, w2);
}

int minDistance(string word1, string word2) {
    auto w1Len = word1.length();
    auto w2L
}
