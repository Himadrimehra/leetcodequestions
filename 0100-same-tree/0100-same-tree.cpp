class Solution {
public:
    bool inorder(TreeNode* p, TreeNode* q)
    {
       
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;

      
        if(p->val != q->val)
            return false;

        return inorder(p->left, q->left) &&
               inorder(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return inorder(p, q);
    }
};