class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long large=LLONG_MIN;
         long long second=LLONG_MIN;
         long long third=LLONG_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
              if (nums[i] == large || nums[i] == second || nums[i] == third) continue; 
           else if(nums[i]>large)
            {
                third=second;
                second=large;
                large=nums[i];
            }
            else if(nums[i]>second)
            {
                third=second;
                second=nums[i];
            }
            else if(third<nums[i])
            {
               third=nums[i];
            }
        }
        if(third==LLONG_MIN)
        {
            return large;
        }
        else 
        {
            return third;
        }
    }
};