class Solution {
public:
   int maxrow(vector<vector<int>>& mat, int mid, int rs, int cs)
{
    int idx = 0; 
    for (int i = 1; i < rs; i++)
    {
        if (mat[i][mid] > mat[idx][mid])
        {
            idx = i;
        }
    }
    return idx; 
}

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int rs=mat.size(),cs=mat[0].size();
       int l=0,h=cs-1;
       while(l<=h)
       {
        int mid=l+(h-l)/2;
     int   row=maxrow(mat,mid,rs,cs);
      int left,right;
        if(mid-1>=0)
        {
             left=mat[row][mid-1];
        }
        else 
        {
            left=-1;
        }
        if(mid+1<cs)
        {
             right=mat[row][mid+1];
        }
        else 
        {
            right=-1;
        }
        if(mat[row][mid]>left&&mat[row][mid]>right)
        {
            return {row,mid};
        }
        else if(mat[row][mid]<left)
        {
             h=mid-1;
        }
        else 
        {
            l=mid+1;
        }
       }
       return {-1,-1}; 
    }
};