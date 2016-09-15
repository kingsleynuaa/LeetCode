//从二进制码最右边开始判断是否为1，为1存储，并下次开始之间左移一位

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for(uint32_t i = 1; i != 0; i <<= 1)
        {
            result <<= 1;
            if(n & 1)
                result |= 1;
            n >>= 1;
        }
        return result;
    }
};
