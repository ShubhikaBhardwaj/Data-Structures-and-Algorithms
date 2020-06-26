class Solution {
public:
    bool find(TreeNode* node,int data)
    {
        if(node==NULL)return false;

        if(node->val==data)return true;

        return find(node->left,data)||find(node->right,data);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL)return root;

        if(root->val==p&&root->val==q)return root;

        bool lp=find(root->left,p);
        bool lq=find(root->left,q);
        bool rp=find(root->right,p);
        bool rq=find(root->right,q);

        if(lp==true&&lq==true)
        return lowestCommonAncestor(root->left,p,q);

        if(rp==true&&rq==true)
        return lowestCommonAncestor(root->right,p,q);

        if((lp&&rq)||(lq&&rp))
        return root;

        return root;
    }
};