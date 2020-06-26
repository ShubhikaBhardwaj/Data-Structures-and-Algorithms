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

        if((root->val==p->val)&&(root->val==q->val))return root;

        //  bool lp=find(root->left,p->val);
        // bool lq=find(root->left,q->val);
        // bool rp=find(root->right,p->val);
        // bool rq=find(root->right,q->val); 

        
        if(find(root->left,p->val)&&find(root->left,q->val))
        return lowestCommonAncestor(root->left,p,q);

        if(find(root->right,p->val)&&find(root->right,q->val))
        return lowestCommonAncestor(root->right,p,q);

       //if ((lp&&rq)||(lq&&rp))
       // return root;

        return root;
    }
};