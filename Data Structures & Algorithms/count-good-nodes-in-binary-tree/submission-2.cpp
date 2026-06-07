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
    int totalgoodNodes = 0;
public:
    int goodNodes(TreeNode* root) {
        // so basically i am thinking of a approach in which we will traverse every node of the tree
        // and consider each value if the current maxm value of the path is equal
        // to the current node then goodnodes++ otherwise continue or return
        if(!root) return 0;
        dfs(root,root->val);
        return totalgoodNodes;
    }

    void dfs(TreeNode* root,int maxValue){
        if(!root) return;
        if(maxValue <= root->val){
            totalgoodNodes++;
        }

        maxValue = max(maxValue , root->val);
        dfs(root->left , maxValue);
        dfs(root->right , maxValue);
    }
};
