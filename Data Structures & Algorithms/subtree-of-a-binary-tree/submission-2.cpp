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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string treeString;
        string subTreeString;
        serialize(root,treeString);
        serialize(subRoot , subTreeString);

        return treeString.find(subTreeString)!=string::npos;


    }

    void serialize(TreeNode* root , string& word){
        if(!root){
            word+="#,";
            return;
        }

        word += to_string(root->val) + ",";
        serialize(root->left,word);
        serialize(root->right,word);
    }





};
