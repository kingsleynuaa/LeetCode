class Solution {
public:
//使用异或得到相加值，使用位与运算（左移一位）得到进位
    int getSum(int a, int b) {
        while(b){
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
    
};
