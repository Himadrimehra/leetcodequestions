class Solution {
public:
long long  inversion(vector<int>& nums,int low,int mid,int high)
{
    int right=mid+1;
    long long count=0;
    for(int i=low;i<=mid;i++)
    {
        while(right<=high && nums[i]>2LL*nums[right])
        {
            right++;
        }
        count+=right-(mid+1);
    }
    return count;
}
void merge(vector<int>& nums,int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
   vector<int>temp;
   while(left<=mid && right <=high)
   {
    if(nums[left]<=nums[right])
    {
        temp.push_back(nums[left]);
        left++;
    }
    else 
    {
        temp.push_back(nums[right]);
        right++;
    }
   }
   while(left<=mid)
   {
      temp.push_back(nums[left]);
      left++;
   }
   while(right<=high)
   {
    temp.push_back(nums[right]);
    right++;
   }
   for(int i=low;i<=high;i++)
   {
    nums[i]=temp[i-low];
   }
}
  long long mergesort(vector<int>& nums,int low,int high)
  {
    long long count=0;
    if(low>=high)
    return count;
    int mid=low+(high-low)/2;
   count+= mergesort(nums,low,mid);
   count+= mergesort(nums,mid+1,high);
   count+=inversion(nums,low,mid,high);
   merge(nums,low,mid,high);
   return count;
  }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};