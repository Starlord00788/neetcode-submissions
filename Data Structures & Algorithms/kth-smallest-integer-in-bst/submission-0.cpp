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
    int answer=INT_MIN;
    int target;
public:
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        dfs(root);
        return answer;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        if(answer!=INT_MIN) return;

        dfs(root->left);
        target--;
        if(target==0){
            answer = root->val;
            return;
        } 

        dfs(root->right);

    }
};
