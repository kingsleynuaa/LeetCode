class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<vector<int>> list;
        if(rowIndex < 0) return result;
        
        for(int i = 0; i < rowIndex+1; i++)
        {
            list.push_back(result);
        }
        
        list[0].push_back(1);
        for(int i = 1; i < rowIndex+1; i++)
        {
            list[i].push_back(1);
            int num = list[i-1].size();
            for(int j = 1; j < num; j++)
            {
                list[i].push_back(list[i-1][j]+list[i-1][j-1]);
            }
            list[i].push_back(1);
        }
        
        result = list[rowIndex];
        return result;
    }
};
