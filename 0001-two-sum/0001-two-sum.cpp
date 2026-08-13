class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int moreneed=target-nums[i];
            if(mp.find(moreneed)!=mp.end())
            {
              return {mp[moreneed],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};