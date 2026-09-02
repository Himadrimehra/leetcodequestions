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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long >>q;
        q.push({root,0});
        int maxwidth=0;
        while(!q.empty())
        {
             int currentsize=q.size();
            unsigned long long startindex=q.front().second;
            unsigned long long endindex=q.back().second;
          maxwidth=max(maxwidth,(int)(endindex-startindex+1));
          for(int i=0;i<currentsize;i++)
          {
              auto node=q.front();
              q.pop();
              if(node.first->left!=NULL)
              {
                q.push({node.first->left,node.second*2+1});
              }
              if(node.first->right!=NULL)
              {
                q.push({node.first->right,node.second*2+2});
              }
          }
        }
        return maxwidth;
    }
};