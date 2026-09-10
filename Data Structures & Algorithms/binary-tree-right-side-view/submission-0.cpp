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
    vector<int> rightSideView(TreeNode* root) {
        auto curptr = root;
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto topVal = q.front();
            q.pop();
            int i = topVal.second;
            if(ans.size() == i){
                ans.push_back(topVal.first->val);
            } else {
                ans[i] = topVal.first->val;
            }
            if(topVal.first->left!=NULL){
                q.push({topVal.first->left,i+1});
            }
            if(topVal.first->right!=NULL){
                q.push({topVal.first->right,i+1});
            }
        }
        return ans;
    }
};
