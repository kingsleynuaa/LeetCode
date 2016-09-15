class Solution {
//二进制加法模拟算法
//分别考虑当前值和进位位
//当前值只需考虑两个对应位与carry标志的异或运算
//进位需要分别考虑：当上次进位为1时，本次进位两个对应位中只需有一个为1即可进位，否则需要两个都为1才能进位
public:
    string addBinary(string a, string b) {
        string result;
        if(a.size() == 0) return b;
        else if(b.size() == 0) return a;
        
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        for(; i >=0 && j >= 0; i--, j--)
        {
            result.push_back(((a[i]-'0') ^ (b[j]-'0')^carry)+'0');
            if(carry == 1) carry = ((a[i]-'0') | (b[j]-'0')) & carry;
            else if(carry == 0) carry = (a[i]-'0') & (b[j]-'0');
            cout << carry;
        }
        while(i >= 0) 
        {
            result.push_back((a[i]-'0')^carry+'0');
            carry = (a[i]-'0')&carry;
            i--;
        }
        while(j >= 0) 
        {
            cout << j;
            result.push_back((b[j]-'0')^carry+'0');
            carry = (b[j]-'0')&carry;
            j--;
        }
        if(carry == 1) result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
