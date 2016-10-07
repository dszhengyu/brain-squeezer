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
int uniquePaths(int m, int n);

void solution(istream &in, ostream &out) {
   int m,n;
   int result;
   in >> m >> n;
   result = uniquePaths(m, n);
   out << result << endl;
}

int uniquePaths(int m, int n) {
    vector<vector <int>> grid (m + 1, vector<int> (n + 1, 0));
    grid[m][n - 1] = 1;
    for (int i = (m - 1); i >= 0; --i) {
        for (int j = (n - 1); j >= 0; --j) {
            grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
        }
    }
    return grid[0][0];
}
