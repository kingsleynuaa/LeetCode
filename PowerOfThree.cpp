class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        
        double tmp = n;
        
        while(tmp > 1)
        {
            tmp = tmp/3.0;
        }
        
        if(tmp == 1) 
            return true;
        else return false;
        
        
    }
};
