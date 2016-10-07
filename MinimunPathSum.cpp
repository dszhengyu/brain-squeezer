#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int minPathSum(vector<vector<int>>& grid);

int main()
{
   int m, n;
   int result;
   cin >> m >> n;
   //cout << "m = " << m << ", n = " << n << endl;
   vector<vector<int>> grid(m, vector<int> (n, 0));
   int num;
   for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> num;
            grid[i][j] = num;
            //cout << "i = " << i << " j = " << j << " num = " << num << endl;
        }
   }
   result = minPathSum(grid);
   cout << result << endl;
}

int minPathSum(vector<vector<int>>& grid) {
    int m, n;
    m = grid.size();
    n = grid[0].size();
    if ((m == 1) || (n == 1)) {
        int sum = 0;
        for (auto line : grid) {
            for (auto num : line) {
                sum += num;
            }
        }
        return sum;
    }
    for (int i = (m - 1); i >= 0; --i) {
        for (int j = (n - 1); j >= 0; --j) {
            if ((i == (m - 1)) && (j == (n - 1))) {
                continue;
            }
            if (i == (m - 1)) {
                grid[i][j] += grid[i][j + 1];
                continue;
            }
            if (j == (n - 1)) {
                grid[i][j] += grid[i + 1][j];
                continue;
            }
            grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
        }
    }
    return grid[0][0];
}
