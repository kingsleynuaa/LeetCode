class Solution {
public:
//传统方法分别计算最后比较最大值，复杂度为O(n),超时
//考虑数字不变，系数变化
    int maxRotateFunction(vector<int>& A) {
        if(A.size() == 0) return 0;
        
        long long allSum = 0;
        long long sum = 0;
        
        for(int i = 0; i < A.size(); i++)
        {
            allSum += i*A[i];
            sum += A[i];
        }
        
        long long result = allSum;
        cout << result;
        for(int i = 0; i < A.size(); i++)
        {
            allSum -= sum;
            allSum += A[i];
            allSum += A[i]*(A.size()-1);
            if(allSum >= result) result = allSum;
        }
        return result;
        
    }
};
