class Solution {
    stack<int> st;

public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        vector<int> nge(m);
        unordered_map<int, int> mp;

      
        for(int i = 0; i < m; i++)
        {
            mp[nums2[i]] = i;
        }

       
        for(int i = m - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                nge[i] = -1;
            }
            else
            {
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }

      
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            int index = mp[nums1[i]];
            ans.push_back(nge[index]);
        }

        return ans;
    }
};