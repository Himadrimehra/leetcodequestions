class Solution {
public:
    bool ispalindrome(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(s.empty())
        {
            return "";
        }
        string ans=s.substr(0,1);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(ispalindrome(i,j,s))
                {
                    if(j-i+1>ans.size())
                    {
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};