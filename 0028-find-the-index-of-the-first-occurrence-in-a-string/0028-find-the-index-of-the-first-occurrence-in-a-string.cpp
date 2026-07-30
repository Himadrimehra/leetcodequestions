class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {

            if (haystack[i] == needle[0]) {

                int l = i;
                int k = 0;

                while (k < m && l < n && haystack[l] == needle[k]) {
                    l++;
                    k++;
                }

                if (k == m)
                    return i;
            }
        }

        return -1;
    }
};