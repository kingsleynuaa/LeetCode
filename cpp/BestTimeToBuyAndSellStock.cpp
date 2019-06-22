class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size  = prices.size();
        if(size < 2) return 0;
        
        int min = prices.at(0);
        int maxProfit = 0;
        vector<int>::iterator iter;
        for(iter = prices.begin(); iter != prices.end(); iter++)
        {
            if(*iter < min) min = *iter;
            int temp = *iter - min;
            if(temp > maxProfit)
                maxProfit = temp;
        }
        
        return maxProfit;
        
        
    }
};
