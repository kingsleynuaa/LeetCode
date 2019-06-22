class Solution {
public:
    string convert(string &say)
    {
        stringstream ss;
        int count  = 0;
        char last = say[0];
        for(size_t i = 0; i <= say.size(); i++)
        {
            if(say[i] == last)
                count++;
            else{
                ss << to_string(count) + last;
                count = 1;
                last = say[i];
            }
        }
        
        return ss.str();
    }
    string countAndSay(int n) {
        
        if(n <= 0) return string();
        string result[n];
        result[0] = "1";
        for(int i = 1; i < n; i++)
            result[i] = convert(result[i-1]);
        
        return result[n-1];
        
        
    }
};
