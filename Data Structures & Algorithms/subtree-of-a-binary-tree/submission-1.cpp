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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL ){
            if(q==NULL) return true;
            return false;
        }
        if(q == NULL) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        bool childrenResult = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        bool sameRootResult = false;
        if(root->val == subRoot->val){
            sameRootResult = isSameTree(root->left,subRoot->left) && isSameTree(root->right,subRoot->right);
        }
        return childrenResult || sameRootResult;
    }
};
