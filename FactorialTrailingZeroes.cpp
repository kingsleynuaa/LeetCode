class Solution {
public:
    int trailingZeroes(int n) {
        //寻找n！中因子5的个数
        int ret = 0;
        while(n)
        {
            ret += n/5;
            n /= 5;
        }
        return ret;
    }
};
