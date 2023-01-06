class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int c=0,i=0,n=costs.size();
        while(i<n&&coins>0)
        {
            if(coins>=costs[i])
            {
                c++;
                coins-=costs[i];
                i++;
            }
            else 
                break;
        }
        return c;
    }
};
