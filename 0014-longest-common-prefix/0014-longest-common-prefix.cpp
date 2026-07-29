class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        int m=strs[0].size();
        int k=strs[n-1].size();
        string ans="";
        for(int i=0;i<m && i<k;i++)
        {
           if(strs[0][i] == strs[n-1][i])
        {
                 ans += strs[0][i];
          }
          else
      {
          break;
        }
            
        }
        return ans;
    }
};