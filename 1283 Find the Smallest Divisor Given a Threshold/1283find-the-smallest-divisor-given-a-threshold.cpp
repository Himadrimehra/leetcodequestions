class Solution {
public:
   int lessthenthreshold(vector<int>&nums,int mid,int threshold){
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
       sum += ceil((double)nums[i] / mid);
    }
    return sum;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=*max_element(begin(nums),end(nums));
        int ans=-1;
        while(l<=h)
        {
          int mid=l+(h-l)/2;
          if(lessthenthreshold(nums,mid,threshold)<=threshold)
          {
            ans=mid;
            h=mid-1;
          }  
          else 
          {
            l=mid+1;
          }
        }
      return ans;  
    }
};