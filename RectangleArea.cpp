class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int result = (C - A)*(D - B) + (G - E)*(H - F);
        int A1 = max(A, E), B1 = max(B, F), C1 = min(C, G), D1 = min(D, H); //抽象出一个交叉的矩形，感悟到数学的美妙啊
        if (D1 <= B1 || C1 <= A1) return result;
         return result - (D1 - B1) * (C1 - A1);
        
        
    }
};
