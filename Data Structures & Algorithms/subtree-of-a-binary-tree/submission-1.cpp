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
    bool result = false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        depth(root, subRoot);
        return result;
    }

    void depth(TreeNode* root,TreeNode* subRoot){
        if(!root || !subRoot) return;
        if(root->val == subRoot->val){
            result = condition(root,subRoot) | result;
        }
        depth(root->left , subRoot);
        depth(root->right , subRoot);
    }

    bool condition(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if((!root && subRoot) || (root && !subRoot)) return false;
        else if(root && subRoot && root->val!=subRoot->val) return false;

        return condition(root->left , subRoot->left) && condition(root->right , subRoot->right);
    }

};
