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
        int d = 0;
        if(root->left != NULL){
            d = max(d, maxDepth(root->left)+1);
        }
        if(root->right != NULL){
            d = max(d, maxDepth(root->right)+1);
        }
        return d;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int diameter1 = 0;
        int diameter2 = 0;
        int diameter3 = 0;
        if(root->left != NULL){
            diameter2 = diameterOfBinaryTree(root->left);
        }
        if(root->right != NULL){
            diameter3 = diameterOfBinaryTree(root->right);
        }
        if(root->left!=NULL && root->right!=NULL){
            diameter1 = maxDepth(root->left) + maxDepth(root->right) + 2;
        } else if(root->left !=NULL){
            diameter1 = maxDepth(root->left) + 1;
        } else if(root->right !=NULL){
            diameter1 = maxDepth(root->right) + 1;
        }
        // cout<<"Root"<<root->val<<" diameter1 "<<diameter1<<" diameter2 "<<diameter2<<" diameter3 "<<diameter3<<endl;
        return max(diameter1,max(diameter2,diameter3));
    }
};
