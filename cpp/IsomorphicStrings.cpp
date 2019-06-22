class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size = s.length();
        map<char,char> mp;
        
        for(int i = 0; i < size; i++)
        {
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = t[i];
            else if(mp[s[i]] != t[i])
                return false;
        }
        
        mp.clear();
        for(int i = 0; i < size; i++)
        {
            if(mp.find(t[i]) == mp.end())
                mp[t[i]] = s[i];
            else if(mp[t[i]] != s[i])
                return false;
        }
        
        return true;
        
    }
};
