class Solution {
public:
bool validsubarray(vector<int>&nums,int mid,int k)
{
    int ele=0;
    int sub=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mid)
        return false;
        if(ele+nums[i]<=mid)
        {
            ele=ele+nums[i];
        }
        else
        {
            sub++;
            ele=nums[i];
        }
        
    }
    if(sub<=k)
    {
        return true;
    }
    return false;
}
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(begin(nums),end(nums));
        int r=0;
        for(int i=0;i<nums.size();i++)
        {
            r=r+nums[i];
        }
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(validsubarray(nums,mid,k))
            {
              ans=mid;
              r=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        return ans;
        
    }
};