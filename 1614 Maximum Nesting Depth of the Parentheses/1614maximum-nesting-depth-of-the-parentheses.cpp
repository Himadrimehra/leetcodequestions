class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
                maxans = max(maxans, count); 
            } 
            else if (s[i] == ')') {
                count--; 
            }
        }

        return maxans;
    }
};
