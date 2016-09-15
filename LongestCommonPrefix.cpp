class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.size() == 0) return result;
        
        
        int column = strs[0].size();
        int row = strs.size();
        for(int i = 1; i < row; i++)
            if(strs[i].size() < column)
                column = strs[i].size();
        
        for(int i = 0; i < column; i++)
        {
            result.push_back(strs[0][i]);
            for(int j = 1; j < row; j++)
                if(result[i] == strs[j][i])
                    continue;
                else 
                {
                    result.pop_back();
                    return result;
                }
        }
        return result;
        
    }
};
