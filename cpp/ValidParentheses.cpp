class Solution {
public:
    bool isValid(string ss) {
        if(ss.size() == 0 || ss.size()%2 != 0) return false;
        
        stack<char> s;
        
        for(size_t i = 0; i < ss.size(); i++)
        {
            char ch = ss[i];
            if(ch == ')' || ch == ']' || ch == '}')
            {
                if(s.empty())
                    return false;
                else{
                    char left = s.top();
                    s.pop();
                    if((ch == ')' && left != '(') || (ch == ']' && left != '[') || (ch == '}' && left != '{') )
                        return false;
                }
            }
            else s.push(ss[i]);
            
        }
       
        
        return s.empty();
        
    }
};
