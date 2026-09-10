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
    TreeNode* buildtrees(vector<int>& preorder, vector<int>& inorder, int lp, int li, int rp, int ri, unordered_map<int, int> &mp) {
        int rootVal = preorder[lp];
        TreeNode * root = new TreeNode;
        root->val = rootVal;
        int ind = mp[rootVal];
        // int ind = li;
        // while(ind < ri && inorder[ind]!=rootVal) ind++;
        // cout<<ind<<" "<<rootVal<<endl;
        // if(inorder[ind]!=rootVal){cout<<ind<<" "<<rootVal<<endl; return NULL;} 
        int numleft = ind-li;
        if(ind > li) {
            root->left = buildtrees(preorder,inorder,lp+1,li,numleft+lp-1,ind-1,mp);
        }
        int numright = ri-ind;
        if(numright>0){
            root->right = buildtrees(preorder,inorder,numleft+lp+1,ind+1,rp,ri,mp);
        }
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return buildtrees(preorder,inorder,0,0, preorder.size()-1, inorder.size()-1,mp);
    }
};
