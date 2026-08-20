class Solution {
public:
    vector<int>rightsmaller(vector<int>& heights)
    {
         stack<int>st;
        int n=heights.size();
        vector<int>rightans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
               rightans[i]=n;
            }
            else 
            {
                rightans[i]=st.top();
            }
            st.push(i);
        }
        return rightans;
    }
     vector<int>leftsmaller(vector<int>& heights)
    {
         stack<int>st;
        int n=heights.size();
        vector<int>leftans(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
               leftans[i]=-1;
            }
            else 
            {
                leftans[i]=st.top();
            }
            st.push(i);
        }
        return leftans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size();
       int currentarea;
       int ans=0;
       vector<int>right(n);
       right=rightsmaller(heights);
       vector<int>left(n);
       left=leftsmaller(heights);
       for(int i=0;i<n;i++)
       {
         int width=right[i]-left[i]-1;
          currentarea=heights[i]*width;
          ans=max(ans,currentarea);       
       }      
       return ans;
    }
};