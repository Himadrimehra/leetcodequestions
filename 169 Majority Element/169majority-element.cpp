class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int candidate ;
        for(int num:nums)
        {
            if(count==0)
            {
                candidate=num;
                count=1;
            }
            else if(num==candidate)
            {
                count++;
            }
            else 
            {
                count--;
            }
        }

    int freq=0;
    for(int num:nums)
    {
        if(candidate==num)
        {
            freq++;
        }
    }
    if(freq>n/2)
    {
        return candidate;
    }
    return -1;
    }
};