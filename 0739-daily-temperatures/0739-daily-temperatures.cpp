class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;   // stores indices

        for (int i = n - 1; i >= 0; i--) {

            // Remove temperatures that cannot be the answer
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack is not empty, top is the next warmer day
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // Store current index
            st.push(i);
        }

        return ans;
    }
};