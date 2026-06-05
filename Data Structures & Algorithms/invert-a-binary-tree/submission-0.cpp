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
    TreeNode* invertTree(TreeNode* root) {
        // According to me BFS should be used in this but this will cause a error in this because we dont know how to decide which values go to which node
        invert(root);
        return root;
    }

    void invert(TreeNode* root){
        if(!root) return;
        invert(root->left);
        invert(root->right);
        
        swap(root->left , root->right);
    }


};
