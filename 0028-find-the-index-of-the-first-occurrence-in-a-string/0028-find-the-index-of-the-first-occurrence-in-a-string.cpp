class Solution {
public:
    vector<int>buildlps(string needle)
    {
        int n=needle.size();
        vector<int>lps(n,0);
        int i=0;
        int j=1;
        while(j<n)
        {
           if(needle[i]==needle[j])
           {
             i++;
             lps[j]=i;
             j++;
           }
           else 
           {
            if(i==0)
            {
                lps[j]=0;
                j++;
            }
            else 
            {
                i=lps[i-1];
            }
           }
        }
        return lps ;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int>lps=buildlps(needle);
       int i=0;
       int j=0;
       while(i<n)
       {
        if(haystack[i]==needle[j])
        {
            i++;
            j++;
            if(j==m)
            {
                return i-j;
            }
        }
        else 
        {
            if(j==0)
            {
               i++;
            }
            else 
            {
                j=lps[j-1];
            }
        }
       }
       return -1;
    }
};