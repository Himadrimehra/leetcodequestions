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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if (root == nullptr)
            return ans;

       
        map<int, map<int, multiset<int>>> mp;

        // node, column, row
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int col = current.second.first;
            int row = current.second.second;

            // Store node value
            mp[col][row].insert(node->val);

            // Left child
            if (node->left != nullptr) {
                q.push({
                    node->left,
                    {col - 1, row + 1}
                });
            }

            // Right child
            if (node->right != nullptr) {
                q.push({
                    node->right,
                    {col + 1, row + 1}
                });
            }
        }

        // Traverse columns from left to right
        for (auto &column : mp) {
            
            vector<int> temp;

            // Traverse rows from top to bottom
            for (auto &row : column.second) {
                
                // Values are already sorted
                for (auto &value : row.second) {
                    temp.push_back(value);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};