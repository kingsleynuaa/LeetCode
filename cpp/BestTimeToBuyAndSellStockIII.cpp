class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        
        int *preProfit = new int[n];
        int *postProfit = new int[n];
        
        postProfit[n-1] = 0;   //注释掉这行，RunCode可以通过［4，2，1］，Submit Solution不可以？
        int result = 0;
        
        int min = prices.at(0);
        int max = prices.at(n - 1);
        
        for(int i = 1; i < n; i++)
        {
            if(prices.at(i) < min) min = prices.at(i);
              //  cout << "min: " << min << endl;
            int temp = prices.at(i) - min;
            if(temp > preProfit[i-1]) 
                preProfit[i] = temp;
            else preProfit[i] = preProfit[i-1];
            
            //cout << "Pre:" << preProfit[i] << " ";
        }
        
        for(int i = 0; i < n; i++)
            cout << preProfit[i] << endl;
        
        for(int i = n-2; i >= 0; i--)
        {
            if(prices.at(i) > max) max = prices.at(i);
            int temp = max - prices.at(i);
            //cout << "temp: " << temp << endl;
            if(temp > postProfit[i+1])
                postProfit[i] = temp;
            else postProfit[i] = postProfit[i+1];
            
           // cout << "Post:" << postProfit[i] << " ";
        }
        
        for(int i = 0; i < n; i++)
         cout << postProfit[i] << endl;
        
        int tmp = 0;
        cout << postProfit[n-1];
        for(int i = 0; i < n; i++)
        {
            tmp = preProfit[i] + postProfit[i];
            cout << tmp << " ";
            if(result < tmp)
                result = tmp;
            cout << endl << result << " ";
        }
        
        return result;
        
    }
};
