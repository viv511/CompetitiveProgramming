#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<long long> levelSums;
int lastLevel = 0;

void trav(TreeNode* node, int level) {
    if(node == nullptr) return;
    else {

        if(levelSums.size() == level) {
            levelSums.push_back(0);
        }

        levelSums[level] += node->val;

        lastLevel = max(lastLevel, level);

        trav(node->left, level + 1);
        trav(node->right, level + 1);
    }
}

int maxLevelSum(TreeNode* root) {
    levelSums.clear();
    trav(root, 0);

    int ansIndex = 0;
    long long maxValue = LLONG_MIN;

    for(int i=0; i < levelSums.size(); i++) {
        if(levelSums[i] > maxValue) {
            maxValue = levelSums[i];
            ansIndex = i;
        }
    }

    return ansIndex + 1;
}