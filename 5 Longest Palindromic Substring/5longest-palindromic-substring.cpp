class Solution {
public:
    bool ispalindromic(int i, int j, string &s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {

        if(s.empty()) return "";

        string ans = s.substr(0,1);

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(ispalindromic(i, j, s))
                {
                    if(j - i + 1 > ans.length())
                    {
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return ans;
    }
};