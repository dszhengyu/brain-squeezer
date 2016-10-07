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
int maxSubArray(vector<int> &nums);

void solution(istream &in, ostream &out) {
    vector<int> vecInt;
    int read;

    while (in >> read) {
        vecInt.push_back(read);
    }

    out << maxSubArray(vecInt) << endl;
}

int maxSubArray(vector<int> &nums) {
    int maxSum = INT32_MIN;
    int currentSum = 0;

    for (const int num : nums) {
        currentSum += num;
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}
