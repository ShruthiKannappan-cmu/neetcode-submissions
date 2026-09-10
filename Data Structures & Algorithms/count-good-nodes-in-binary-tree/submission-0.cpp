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
    int goodNodes(TreeNode* root) {
        int cnt = 1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        while(!q.empty()){
            auto topVal = q.front();
            q.pop();
            int newVal = max(topVal.first->val,topVal.second);
            if(topVal.first->left!=NULL){
                if(topVal.first->left->val >= newVal) cnt++;
                q.push({topVal.first->left,newVal});
            }
            if(topVal.first->right!=NULL){
                if(topVal.first->right->val >= newVal) cnt++;
                q.push({topVal.first->right,newVal});
            }
        }
        return cnt;
    }
};
