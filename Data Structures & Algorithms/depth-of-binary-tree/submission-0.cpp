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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int d = 1;
        if(root->left != NULL){
            d = max(d, maxDepth(root->left)+1);
        }
        if(root->right != NULL){
            d = max(d, maxDepth(root->right)+1);
        }
        return d;
    }
};
