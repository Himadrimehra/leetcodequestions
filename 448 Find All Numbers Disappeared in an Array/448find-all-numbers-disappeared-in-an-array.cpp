class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      int n=nums.size();
      vector<int>result;
      for(int i=0;i<n;i++)
      {
        int indx=abs(nums[i])-1;
        if(nums[indx]<0)
        {
             continue;
        }
        else 
        {
            nums[indx]=nums[indx]*-1;
        }
      }
      for(int i=0;i<n;i++)
      {
        if(nums[i]>0)
        {
            result.push_back(i+1);
        }
      }
      return result; 
    }
};