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
    if (nums.size() < 2) {
        return nums[0];
    }

    int maxSum = INT32_MIN;
    int currentSum = 0;

    //a. if nums[i] >=0, data[i + 1] store the index of a range max the sum
    //b. if nums[i] < 0, data[i + 1] store the sum of the previous range, or -1 if no previous range
    vector<int> data(nums.size() + 1);
    data[0] = 1;

    for (size_t i = 0; i < nums.size(); ++i) {
        const int num = nums[i];
        if (num >= 0) {
            currentSum += num;
            data[i + 1] = data[i];
            int position = data[i];
            while ((position - 1) > 0 && nums[position - 1] < 0 && ((num + nums[position - 1]) >=0)) {
                cout << "haha " << endl;
                cout << "num " << num << endl;
                cout << "position " << i << endl;
                currentSum += data[position - 1] + nums[position - 1];
                data[i + 1] = (position - 2 > 0) ? data[position - 2] : data[i + 1];
                position = position - 2;
            }
            maxSum = max(maxSum, currentSum);
        }
        else {
            maxSum = max(maxSum, num);
            data[i + 1] = currentSum;
            currentSum = 0;
        }
    }

    return maxSum;
}
