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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode* ,int>> q;
        int cur_level = -1;
        q.push({root,0});
        while(!q.empty()){
            auto topVal = q.front();
            q.pop();
            if(cur_level < topVal.second){
                vector<int> v;
                v.push_back(topVal.first->val);
                ans.push_back(v);
                cur_level = topVal.second;
            } else {
                ans[cur_level].push_back(topVal.first->val);
            }
            if(topVal.first->left!=NULL){
                q.push({topVal.first->left,topVal.second+1});
            }
            if(topVal.first->right!=NULL){
                q.push({topVal.first->right,topVal.second+1});
            }
        }
        return ans;
    }
};
