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

    bool result = true;
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        depth(root);
        return result;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        int leftlength = depth(root->left);
        int rightlength = depth(root->right);
        if(abs(leftlength-rightlength)>1) result = false;

        return 1 + max(leftlength , rightlength);
    }

};
