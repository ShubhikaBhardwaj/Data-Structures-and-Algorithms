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
    int height(TreeNode* root)
    {
        if(root==NULL)return -1;

        return max(height(root->left),height(root->right))+1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {

        if(root==NULL)return 0;

        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);

        int lh=height(root->left);
        int rh=height(root->right);

        return max(max(ld,rd),lh+rh+2);
        
    }
};