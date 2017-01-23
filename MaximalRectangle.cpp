#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <utility>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix);
int largestRectangleArea(vector<int> heights);

int main()
{
    char c;
    vector<vector<char>> charMap;
    vector<char> line;
    while (cin >> c) {
        if (c == 'n') {
            charMap.push_back(line);
            line = vector<char>();
            continue;
        }
        line.push_back(c);
    }
    
    cout << maximalRectangle(charMap) << endl;
    
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    size_t m = matrix.size();
    size_t n = matrix[0].size();

    int maxArea = 0;
    vector<int> height(n, 0);
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') {
                ++height[j];
            }
            else {
                height[j] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
}

int largestRectangleArea(vector<int> heights) {
    heights.push_back(0);
    stack<int> stack;
    int maxArea = 0;
    
    for (int i = 0; (size_t)i < heights.size(); ++i) {
        while (!stack.empty() && heights[stack.top()] > heights[i]) {
            int currentHeight = heights[stack.top()];
            stack.pop();
            int startIndex = stack.empty() ? -1 : stack.top();
            maxArea = max (maxArea, currentHeight * (i - startIndex - 1));
        }   
        stack.push(i);
    }   
    return maxArea;
}
