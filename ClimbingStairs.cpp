#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

int climbStairs(int n) {
    list<int> currentList;
    list<int> nextList;
    currentList.push_back(1);
    currentList.push_back(2);
    int num;
    int success = 0;
    int possible = n + 1;
    while (possible--) {
        while (currentList.size() != 0) {
            num = currentList.front();
            //cout << "get " << num << endl;
            currentList.pop_front();
            if (num > n) {
                continue;
            }
            if (num == n) {
                //cout << "success " << num << endl;
                ++success;
                continue;
            }
            if (num < n) {
                nextList.push_back(num + 1);
                nextList.push_back(num + 2);
            }
        }
        currentList.swap(nextList);
    }
    return success;
}
 int climbEasy(int n) {
    if (n <= 2) {
        return n;
    }
    vector<int> solution(n + 1, 0);
    solution[1] = 1;
    solution[2] = 2;
    for (int i = 3; i < (n + 1); ++i) {
        solution[i] = solution[i - 1] + solution[i - 2];
    }
    return solution[n];
 }

int main()
{
    int n;
    cin >> n;
    cout << climbEasy(n) << endl;
}
