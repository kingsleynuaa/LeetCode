class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<char,bool> mp1;
        unordered_map<char,bool> mp2;
        unordered_map<char,bool> mp3;
        
        for(int i = 0; i < board.size(); i++)
        {
            mp1.clear();
            mp2.clear();
            mp3.clear();  
            //其实我觉得这么写是有问题的？因为最外层的for循环每次只有一行的数。这个算法只是满足了这9个数在
            //三种条件下没有冲突。
////懂了，外层循环只是一个编号，下面三个if分别会对应到第i行，第i 列，第i个九宫格，哈哈哈
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    if(mp1[board[i][j]] == true)
                    {
                        cout << "heng";
                        return false;
                    }
                    mp1[board[i][j]] = true;
                }
                
                if(board[j][i] != '.')
                {
                    if(mp2[board[j][i]] == true)
                        return false;
                    mp2[board[j][i]] = true;
                }
                
                if(board[i/3*3+j/3][i%3*3+j%3] != '.')
                {
                    if(mp3[board[i/3*3+j/3][i%3*3+j%3]] == true)
                        return false;
                    mp3[board[i/3*3+j/3][i%3*3+j%3]] = true;
                }
            }
        }
                
    return true;
    }
};
