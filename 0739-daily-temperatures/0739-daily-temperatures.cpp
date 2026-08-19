class Solution {
    stack<int>st;
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
          int n=temperatures.size();
        vector<int>ans(n);
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }
            if(st.empty())
            {
               ans[i]=0;
            }
            else 
            {
               ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};