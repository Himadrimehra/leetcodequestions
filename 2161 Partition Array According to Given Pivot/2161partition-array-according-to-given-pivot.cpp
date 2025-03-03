class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>larger,smaller,same,result;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            {
                smaller.push_back(nums[i]);
            }
            else if(nums[i]>pivot)
            {
                larger.push_back(nums[i]);
            }
            else if(nums[i]==pivot)
            {
                same.push_back(nums[i]);
            }

        }
        result.insert(result.end(),smaller.begin(),smaller.end());
        result.insert(result.end(),same.begin(),same.end());
        result.insert(result.end(),larger.begin(),larger.end());
        return result;
    }
};