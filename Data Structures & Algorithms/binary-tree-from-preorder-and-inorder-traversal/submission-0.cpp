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
    unordered_map<int , int> mpp;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0 ; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = dfs(preorder , 0 , preorder.size()-1 , inorder , 0 ,inorder.size()-1);
        return root;
    }

    TreeNode* dfs(vector<int>& preorder , int preStart , int preEnd , vector<int>& inorder , int inStart , int inEnd ){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int indexforRoot = mpp[preorder[preStart]];
        int numsleft = indexforRoot - inStart;

        root->left = dfs(preorder , preStart+1 , preStart+numsleft , inorder , inStart , indexforRoot-1);
        root->right = dfs(preorder , preStart + numsleft+1 , preEnd , inorder , indexforRoot+1 , inEnd);
        return root;


    }
};
