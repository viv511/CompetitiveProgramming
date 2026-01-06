
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//simultaneous dfs o(n) time, o(h) space

class Solution {
public:
    bool dfs(TreeNode* l, TreeNode* r) {
        if(l == nullptr && r == nullptr) return true;
        if(l == nullptr || r == nullptr) return false;
        
        //both are not null
        //safety: not null so deref is okay!
        if((l->val == r->val) && dfs(l->left, r->right) && dfs(l->right, r->left)) {
            return true;
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return dfs(root->left, root->right);
    }
};