class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>hasmap(n,0);
        for(int i=0;i<n;i++)
        {
            hasmap[nums[i]]++;
            if(hasmap[nums[i]]>1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};