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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);
        while(st.top()->left!=NULL) st.push(st.top()->left);
        int cnt = 1;
        while(cnt<k && !st.empty()){
            auto topVal = st.top();
            cnt++;
            st.pop();
            if(topVal->right!=NULL) {st.push(topVal->right);
            while(st.top()->left!=NULL) st.push(st.top()->left);}
        }
        return st.top()->val;

    }
};
