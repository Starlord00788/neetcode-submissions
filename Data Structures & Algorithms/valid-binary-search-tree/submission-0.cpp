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
    bool isValidBST(TreeNode* root) {
        return dfs(root , INT_MIN , INT_MAX);
    }

    bool dfs(TreeNode* root , int minRange , int maxRange){
        if(!root) return true;

        if(root->val <= minRange || root->val >= maxRange) return false;

        return dfs(root->left,minRange , root->val) && dfs(root->right , root->val , maxRange);
    }
};
