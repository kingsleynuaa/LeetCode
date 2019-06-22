class Solution 
{
    public:
     int integerReplacement(int n) {
        if (n <= 1) {
            return 0;
        } else if (n == INT_MAX) {
            return 32;
        }
        if(n == 3)  return 2;
        
        if (n & 1) {
            return (numTrailingOnes(n) > 1) ? (integerReplacement(n + 1)+1) : (integerReplacement(n - 1)+1);
        }
        else {
            return integerReplacement(n >> 1) + 1;
        }
    }

    int numTrailingOnes(int num) {
        int shift = 0;
        while (((num >> shift) & 1)) {
            shift++;
        }
        cout << shift;
        return shift;
    }
};
