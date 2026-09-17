class Solution {
public:
 vector<int> genraterow(int numRows)
 {
    vector<int>ansrow;
        long long ans=1;
        ansrow.push_back(1);
        for(int col=1;col<numRows;col++)
        {
           ans=ans*(numRows-col);
           ans=ans/col;
           ansrow.push_back(ans);
        }
        return ansrow;
    
 }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++)
        {
        ans.push_back(genraterow(i));
        }
        return ans;
    }
};