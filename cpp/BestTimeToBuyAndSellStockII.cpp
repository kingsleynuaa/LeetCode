class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        
        int maxProfit = 0;
        int diff = 0;
        vector<int>::iterator iter;
        for(iter = prices.begin()+1; iter != prices.end(); iter++)
        {
            diff = *iter - *(iter-1);
            if(diff > 0)
                maxProfit += diff;
        }
        
        return maxProfit;
        
    }
};
