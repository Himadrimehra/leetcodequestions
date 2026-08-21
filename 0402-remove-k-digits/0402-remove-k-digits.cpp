class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        for(int i = 0; i < n; i++) {

            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // If k digits are still left to remove
        while(k > 0) {
            st.pop();
            k--;
        }

        string result = "";

        // Stack -> string
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Reverse because stack gives reverse order
        reverse(result.begin(), result.end());

        // Remove leading zeroes
        int i = 0;
        while(i < result.size() && result[i] == '0') {
            i++;
        }

        result = result.substr(i);

        if(result.empty()) {
            return "0";
        }

        return result;
    }
};