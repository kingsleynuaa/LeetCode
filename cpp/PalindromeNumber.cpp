class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int num = x;
        int temp = 0;
        while(x >= 10)
        {
            temp = temp*10 + x%10;
            x /= 10;
        }
        temp = temp*10 + x;
        if(num == temp)   //一定要注意原始数据是否发生了变化
            return true;
        else 
            return false;
    }
};
