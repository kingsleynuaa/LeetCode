class Solution {
public:
//这题其实是有问题的
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        if(num & (num - 1))  return false;
        return num % 3 == 1;
    }     
    
};
