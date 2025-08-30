class Solution {
public:
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>result;
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<result.back()[1])
            {
                result.back()[1]=max(intervals[i][1],result.back()[1]);
            }
            else 
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>hor;
        vector<vector<int>>vert;
        for(auto& coord: rectangles)
        {
            int x1=coord[0];
            int y1=coord[1];
            int x2=coord[2];
            int y2=coord[3];
            hor.push_back({x1,x2});
            vert.push_back({y1,y2});
        }
        vector<vector<int>>result1=merge(hor);
        if(result1.size()>=3)
        return true;
        vector<vector<int>>result2=merge(vert);
         if(result2.size()>=3)
        return true;
        return false;
    }

};