class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>st;
       int n=nums.size();
       if(n==0)return 0;
        int longest=1;
        for(auto num:nums)
        {
            st.insert(num);
        }
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
               int count =1;
                int x=it;
            
            while(st.find(x+1)!=st.end())
            {
                x=x+1;
                count++;
            }
            longest=max(longest,count);
        }
        }
        return longest;
    }
};