class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
          int n=nums.size();
    int count =0;
    int ones=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==1)
        {
            ones++;
        }
        if(nums[i]==0)
        {
            count=max(count,ones);
            ones=0;
        }
    }
     count=max(count,ones);
            return count;
    }
};