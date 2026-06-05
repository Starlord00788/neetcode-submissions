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
    int maxDepth(TreeNode* root) {
        // we can do this using BFS too
        if(!root) return 0;
        int depth = 1;
        DFS(root,depth,1);
        return depth;
    }

    void DFS(TreeNode* root, int& depth , int currentDepth){
        if(!root) return;
        DFS(root->left,depth,currentDepth+1);
        DFS(root->right,depth,currentDepth+1);
        depth = max(depth, currentDepth);
    }
};
