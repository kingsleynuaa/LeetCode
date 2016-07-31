class Solution {
public:
    int squareOfDigit(int n)
    {
        int result = 0;
        int tmp = 0;
        while(n >= 10)
        {
            tmp = n%10;
            result = result + tmp*tmp;
            n = n/10;
        }
        result = result + n*n;
        
        return result;
    }
    
    bool isHappy(int n) {
        if( n < 1) return false;
        unordered_set<int> showedNums;
        showedNums.insert(n);
        
        int temp = squareOfDigit(n);
        showedNums.insert(temp);
        while( 1 )
        {
            if(temp == 1) return true;
            temp = squareOfDigit(temp);
            if (showedNums.find(temp) != showedNums.end())
                return false;
            showedNums.insert(temp);
            
            cout << temp << endl;
        }
        
        
        
        
    }
};
