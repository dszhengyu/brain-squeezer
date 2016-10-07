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

int uniquePaths(vector<vector<int>>& obstacleGrid);

void solution(istream &in, ostream &out) {
   int m, n;
   int result;
   in >> m >> n;
   //out << "m = " << m << ", n = " << n << endl;
   vector<vector<int>> obstacleGrid(m, vector<int> (n, 0));
   int num;
   for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> num;
            obstacleGrid[i][j] = num;
            //out << "i = " << i << " j = " << j << " num = " << num << endl;
        }
   }
   result = uniquePaths(obstacleGrid);
   out << result << endl;
}

int uniquePaths(vector<vector<int>>& obstacleGrid) {
    int m, n;
    m = obstacleGrid.size();
    n = obstacleGrid[0].size();
    //cout << " in function m = " << m << ", n = " << n << endl;
    vector<vector <int>> grid (m + 1, vector<int> (n + 1, 0));
    grid[m][n - 1] = 1;
    for (int i = (m - 1); i >= 0; --i) {
        for (int j = (n - 1); j >= 0; --j) {
            if (obstacleGrid[i][j] == 1) {
                grid[i][j] = 0;
                continue;
            }
            grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
        }
    }
    return grid[0][0];
}
