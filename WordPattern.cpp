class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> str_vector;
        istringstream strIn(str);
        string tempStr;
        while(strIn >> tempStr)
            str_vector.push_back(tempStr);
        
        int sizePattern = pattern.size();
        int sizeStr = str_vector.size();
        if(sizePattern != sizeStr) return false;
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        
        for(int i = 0; i < sizeStr; i++)
        {
            if(mp1.find(pattern[i]) == mp1.end())
                mp1[pattern[i]] = str_vector[i];
            else if(mp1[pattern[i]] != str_vector[i])
                return false;
                
            if(mp2.find(str_vector[i]) == mp2.end())
                mp2[str_vector[i]] = pattern[i];
            else if(mp2[str_vector[i]] != pattern[i])
                return false;
        }
        
        return true;
        
    }
};
