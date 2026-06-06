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
    int diameterOfBinaryTree(TreeNode* root) {
        int nodes = 0;
        dfs(root,nodes);
        return nodes;
    }

    int dfs(TreeNode* root, int& nodes){
        if(!root) return 0;
        int leftlength = dfs(root->left,nodes);
        int rightlength = dfs(root->right,nodes);
        nodes = max(nodes , leftlength + rightlength);

        return 1 + max(leftlength , rightlength);


    }
};
