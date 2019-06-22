class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows <= 0) return result;
        
        vector<int> tmp;
        for(int i  = 0; i < numRows; i++)
            result.push_back(tmp); //对于元素也为vector的vector，比如result，result会初始化，但是result的每个元素却并不会初始化
        
        result[0].push_back(1);
        
        for(int i  = 1; i < numRows; i++)
        {
            int num = result[i-1].size();
            //cout << "num: " << num << endl;
            result[i].push_back(1);
            for(int j = 1; j <= num-1; j++)    
            {
                result[i].push_back(result[i-1][j]+result[i-1][j-1]); 
                //使用result.[]方式只能获取值，却并不会造成对应位置值的改变吗？必须使用push_back()或者insert()吗
            }
            result[i].push_back(1);
        }
        
        return result;
        
    }
};
