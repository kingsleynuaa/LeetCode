class Solution {
public:
    int reverse(int x) {
        const int M = 2147483647;
        bool flag = false;
        if(x < 0) 
        {
            flag = true;
            x = -x;
        }
        
        long long result = 0;
        int n = 0;
        while(x > 0)
        {
            n = x%10;
            result = result*10 + n;
            x /= 10;
        }
        if(result > M) result = 0; 
        return flag == true ? -result:result;
        
    }
};
