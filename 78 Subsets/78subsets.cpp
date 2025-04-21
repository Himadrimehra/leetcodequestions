class Solution {
public:
     void subseq(vector<int>nums,int index,int n,vector<int>&temp,
        vector<vector<int>>&ans)
        {
            if(n==index)
            {
                ans.push_back(temp);
                return ;
            }
            subseq(nums,index+1,n,temp,ans);
        temp.push_back(nums[index]);
         subseq(nums,index+1,n,temp,ans);
         temp.pop_back();
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        subseq(nums,0,n,temp,ans);
        return ans;
    }
};