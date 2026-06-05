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
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int q_size = q.size();
            for(int i=0;i<q_size;i++){
                TreeNode* current = q.front();
                q.pop();

                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
            }
            if(!q.empty()) depth++;
        }

        return depth;
    }
};
