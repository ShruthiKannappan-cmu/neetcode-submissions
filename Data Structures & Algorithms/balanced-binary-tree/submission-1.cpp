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
    int height(TreeNode * root){
        if(root == NULL) return 0;
        int h = 0;
        if(root->right!=NULL){
            h = max(h, height(root->right)+1);
        }
        if(root->left!=NULL){
            h = max(h, height(root->left)+1);
        }
        return h;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int hleft = 0, hright = 0;
        if(root->right!=NULL){
            if(!isBalanced(root->right)) return false;
            hright = height(root->right)+1;
        }
        if(root->left!=NULL){
            if(!isBalanced(root->left)) return false;
            hleft = height(root->left)+1;
        }
        if(abs(hleft-hright) > 1) return false;
        return true;
    }
};
