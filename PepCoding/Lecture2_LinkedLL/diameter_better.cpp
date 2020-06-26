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
    
   pair<int,int> diameter(TreeNode*root)
   {
       if(root==NULL)
       {
           pair<int,int> p;
           p.first=0; p.second=-1;
           return p;
       }
       
       pair<int,int> lp=diameter(root->left);
       pair<int,int> rp=diameter(root->right);

       pair<int,int> p;

       p.first= max(max(lp.first,rp.first),lp.second+ rp.second+2);
       p.second= max(lp.second,rp.second)+1;
       return p;

   }

    
    int diameterOfBinaryTree(TreeNode* root) {
        
    if(root==NULL)return 0;    

    pair<int,int>p=diameter(root);

    return p.first;

    }
};