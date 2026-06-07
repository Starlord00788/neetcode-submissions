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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int t_size = q.size();
            result.push_back((q.front())->val);
            for(int i=0;i<t_size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
            }
        }

        return result;

    }
};
