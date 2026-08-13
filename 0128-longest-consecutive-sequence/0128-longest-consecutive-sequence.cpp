class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=1;
        if(n==0)
        return 0;
       unordered_set<int>st;
       for(int num:nums)
       {
        st.insert(num);
       }
       for(auto it:st)
       {
        if(st.find(it-1)==st.end())
        {
            int x=it;
            int count=1;
        
        while(st.find(x+1)!=st.end()){
            x=x+1;
            count++;
        }
        longest=max(longest,count);
       }
    }
    
    return longest;
}
};