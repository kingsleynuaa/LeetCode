class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        if(n == 0) return false;
        if(n == 1) return true;
        if(n & 1)  return false;
        
        int count = 0;
        while(n)
        {
            n = n >> 1;
            if(n & 1)
                count++;
            
        }
        
        if( count == 1) return true;
        return false;
        
    }
};
