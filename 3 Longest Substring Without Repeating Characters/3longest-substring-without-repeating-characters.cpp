class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int left =0;
        int right=0;
        int maxlen=0;
        while(right<s.size())
        {
            if(hash[s[right]]!=-1 && hash[s[right]]>=left)
            {
                left=hash[s[right]]+1;
            }
            int len=right-left+1;
            maxlen=max(maxlen,len);
            hash[s[right]]=right;
            right++;
        }
        return maxlen;
    }
};