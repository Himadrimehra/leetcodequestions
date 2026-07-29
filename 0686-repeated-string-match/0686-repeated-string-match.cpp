class Solution {
public:
    
    vector<int> buildLPS(string pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

   
    bool KMPMatch(string text, string pattern) {
        vector<int> lps = buildLPS(pattern);

        int i = 0; 
        int j = 0; 

        while (i < text.size()) {

            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == pattern.size()) {
                return true; 
            }

            else if (i < text.size() && text[i] != pattern[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {

        if (a == b)
            return 1;

        string temp = a;
        int repeat = 1;

        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

      
        if (KMPMatch(temp, b))
            return repeat;

        
        temp += a;

        if (KMPMatch(temp, b))
            return repeat + 1;

        return -1;
    }
};