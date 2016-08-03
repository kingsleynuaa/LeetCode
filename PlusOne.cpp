class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        vector<int>::iterator iter;
        digits[digits.size()-1]++;
        //cout << " " << digits[0] << endl;
        
        int tmp = 0;
        for(iter = digits.end()-1; iter != digits.begin()-1; iter--)
        {
            tmp = (*iter + carry)/10;
            *iter = (*iter + carry)%10;
            //cout << "*iter: " << *iter;
            carry = tmp;
            if(carry == 0) break;
            //cout << " " << carry << " ";
        }
        cout << carry;
        if(carry > 0)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
