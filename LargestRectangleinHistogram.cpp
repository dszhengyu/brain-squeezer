#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>

using namespace std;


int largestRectangleArea(vector<int> &heights);

int main()
{
    vector<int> heights;
    int each;
    while (cin >> each) {
        heights.push_back(each);
    }
    cout << largestRectangleArea(heights) << endl;
}

int largestRectangleArea(vector<int> &heights) {
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
