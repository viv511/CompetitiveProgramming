struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode *n) {
    if(n->left == nullptr && n->right == nullptr) return true;

    return false;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return false;

    if(isLeaf(root) && (root->val == targetSum)) return true;

    return hasPathSum(root->left, targetSum - root->val)
        || hasPathSum(root->right, targetSum - root->val);
}