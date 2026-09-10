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
    bool isValid(TreeNode* root, pair<int,bool> lower_bound, pair<int,bool> upper_bound) {
        if(root == NULL) return true;
        if(lower_bound.second && (lower_bound.first >= root->val)) return false;
        if(upper_bound.second && (upper_bound.first <= root->val)) return false;
        bool leftChildResult = true;
        bool rightChildResult = true;
        if(root->left!=NULL){
            leftChildResult = isValid(root->left,lower_bound,{root->val,true});
        }
        if(root->right!=NULL){
            rightChildResult = isValid(root->right,{root->val,true},upper_bound);
        }
        return rightChildResult && leftChildResult;
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,{0,false},{0,false});
    }
};
