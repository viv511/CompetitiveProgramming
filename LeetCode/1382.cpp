//https://leetcode.com/problems/balance-a-binary-search-tree/description/

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

void trav(TreeNode* node, vector<int>& vals) {
    if (node == nullptr) return;

    //L -- data -- R (inorder trav)
    trav(node->left, vals);
    vals.push_back(node->val);
    trav(node->right, vals);
}

TreeNode* buildBalanced(vector<int>& vals, int l, int r) {
    if(l > r) return nullptr;

    int mid = l + (r - l) / 2;
    TreeNode* newRoot = new TreeNode(vals[mid]);
    newRoot->left = buildBalanced(vals, l, mid - 1);
    newRoot->right = buildBalanced(vals, mid + 1, r);

    return newRoot;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodeOrder;
    trav(root, nodeOrder);
    return buildBalanced(nodeOrder, 0, nodeOrder.size()-1);
}