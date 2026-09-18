class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        int longest=1;
        if(n==0)
        return 0;
        for(auto num:nums)
        {
            st.insert(num);
        }
        for(auto num:st)
        {
            if(st.find(num-1)==st.end())
            {
                int count=1;
                int x=num;
                while(st.find(x+1)!=st.end())
                {
                    count++;
                    x++;
                }
                longest=max(longest,count);
            }

        }
        return longest;
    }
};