class Solution {
public:
int canmakebouquet(vector<int>&bloomDay,int mid,int k)
{
    int consecutive=0;
     int bouquet=0;
    for(int i=0;i<bloomDay.size();i++)
    {
         if(bloomDay[i]<=mid)
         {
            consecutive++;
         }
         else 
         {
            consecutive=0;
         }
         if(consecutive==k)
         {
             bouquet++;
             consecutive=0;
         }

    }
    return bouquet;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=0;
        int r = *max_element(begin(bloomDay), end(bloomDay));
          int minD=-1;
        while(l<=r)
        {
           int mid=l+(r-l)/2;
         
           if(canmakebouquet(bloomDay,mid,k)>=m)
           {
            minD=mid;
            r=mid-1;
           }
           else 
           {
            l=mid+1;
           }
        }
        return minD;
    }
};