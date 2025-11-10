//https://leetcode.com/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
#include <math.h>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int height(TreeNode* node) {
    if(node == nullptr) return 0;

    int lHeight = height(node->left);
    if (lHeight == -1) return -1;

    int rHeight = height(node->right);
    if (rHeight == -1) return -1;
    
    if(abs(lHeight - rHeight) > 1) return -1;
    
    //Last case, proceed as normal
    return 1 + max(rHeight, lHeight);
}

bool isBalanced(TreeNode* root) {
    return(height(root) != -1);
}