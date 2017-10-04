#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

bool checkValid(size_t row, size_t col, size_t currentRow) {
    if ((row >=0) && (col >= 0) && (col < currentRow)) {
        return true;
    }
    return false;
}
int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty()) {
        return 0;
    }
    if (triangle.size() == 1) {
        return triangle[0][0];
    }
    vector<int> dp = vector<int>(1);
    dp[0] = triangle[0][0];
    for (size_t i = 1; i < triangle.size(); ++i) {
        vector<int> row = triangle[i];
        vector<int> dpNew = vector<int>(row.size(), 0);
        for (size_t j = 0; j < row.size(); ++j) {
            vector<pair<int, int>> set = vector<pair<int, int>>();
            vector<pair<int, int>> validSet = vector<pair<int, int>>();
            set.push_back(pair<int, int>(i - 1, j));
            set.push_back(pair<int, int>(i - 1, j - 1));
            for (auto candidate : set) {
                bool valid = checkValid(candidate.first, candidate.second, i);
                //cout << "x:" << candidate.first << " y:" << candidate.second << " i:" << i << " j:" << j << " valid:" << valid << endl;
                if (valid) {
                    validSet.push_back(candidate);
                }
            };
            int min = 0x7fffffff;
            for (auto pairCor : validSet) {
                //cout << "    valida x:" << pairCor.first << " y:" << pairCor.second << " i:" << i << " j:" << j << endl;
                if (dp[pairCor.second] < min) {
                    min = dp[pairCor.second];
                }
            }
            //cout << "min:" << min << endl;
            dpNew[j] = min + triangle[i][j];
        }
        dp.swap(dpNew);
        //for (auto single : dp) {
        //    cout << single << " ";
        //}
        //cout << endl;
    }
    int min = 0x7fffffff;
    for (auto num : dp) {
        if (num < min) {
            min = num;
        }
    }
    return min;
}

int main()
{
    vector<vector<int>> input = vector<vector<int>>();
    int num;
    int column = 1;
    int count = 0;
    vector<int> row = vector<int>();
    while (cin >> num) {
        ++count;
        row.push_back(num);
        if (count == column) {
            input.push_back(row);
            row = vector<int>();
            ++column;
            count = 0;
        }
    }
    cout << minimumTotal(input) << endl; 
}
