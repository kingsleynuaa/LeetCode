class Solution {
public:
    int firstUniqChar(string s) {
        int lowercase[26] = {0};
        for(int i = 0; i < s.size(); i++)
            lowercase[s[i]-'a']++;
        
        int i = 0;
        for(; i < s.size(); i++)
            if(lowercase[s[i]-'a'] > 1)
                continue;
            else break;
        if(i == s.size()) 
            return -1;
        else return i;
        
    }
};
