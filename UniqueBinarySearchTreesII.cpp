#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int n);

int main()
{
    int n;
    cin >> n;
    generateTrees(n);
}

vector<TreeNode*> generateTrees(int n) {
}
