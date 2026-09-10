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
    int maxrootpathSum(TreeNode * root, unordered_map<TreeNode*,int> & rootpathsum){
        if(root == NULL) return 0;
        if(rootpathsum.find(root)!= rootpathsum.end()) return rootpathsum[root];
        int sumval = root->val;
        int leftsum = maxrootpathSum(root->left,rootpathsum);
        int rightsum = maxrootpathSum(root->right,rootpathsum);
        int childsum = max(rightsum,leftsum);
        if(childsum>0) sumval+= childsum;
        return rootpathsum[root] = sumval;
    }
    int maxPathSumMap(TreeNode* root, unordered_map<TreeNode*,int> & pathsum,unordered_map<TreeNode*,int> & rootpathsum) {
        if(root == NULL) return 0;
        if(pathsum.find(root)!=pathsum.end()) return pathsum[root];

    
        int max1 = root->val + max(maxrootpathSum(root->right,rootpathsum),0) + max(0,maxrootpathSum(root->left,rootpathsum));
        if(root->left!=NULL){
            max1 = max(max1, maxPathSumMap(root->left,pathsum,rootpathsum));
        }
        if(root->right!=NULL){
            max1 = max(max1, maxPathSumMap(root->right,pathsum,rootpathsum));
        }
        return max1;
    }
    // int max0pathsum()
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        unordered_map<TreeNode*,int>pathsum;
        unordered_map<TreeNode*,int>rootpathsum;
        return maxPathSumMap(root,pathsum,rootpathsum);
    }
};
