class Solution {
public:
    int minimumCost(vector<int>& cost)
  {  int n=cost.size(); 
       sort(cost.begin(),cost.end());
        int min_amount=0,i=0,j=n-1,count=0;
        while(i<=j)
        {
            min_amount+=cost[j];
            j--;
            count++;
            if(count==2&&j>=0)
            {
            j--;
            count=0;
            }
        }  
        return min_amount;
    }
};