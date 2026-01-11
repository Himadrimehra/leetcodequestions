class Solution {
public:
    void solve(int indx, int target, vector<int>& candidates, 
               vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (indx >= candidates.size() || target < 0) return;

      
        if (candidates[indx] <= target) {
            temp.push_back(candidates[indx]);
            solve(indx, target - candidates[indx], candidates, temp, ans);
            temp.pop_back(); 
        }

       
        solve(indx + 1, target, candidates, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, target, candidates, temp, ans);
        return ans;
    }
};
