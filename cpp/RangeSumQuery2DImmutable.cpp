class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        cout << row;
        int column = row > 0 ? matrix[0].size() : 0;
        Matrix = vector<vector<int>>(row+2, vector<int>(column+2,0));
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= column; j++)
            {
                Matrix[i][j] = matrix[i-1][j-1] + Matrix[i-1][j] + Matrix[i][j-1] - Matrix[i-1][j-1];
                cout << matrix[i-1][j-1] << "Matrix[" << i << "][" << j << "] = " << Matrix[i][j] << endl;
            }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return Matrix[row1][col1] - Matrix[row1][col2+1] - Matrix[row2+1][col1] + Matrix[row2+1][col2+1];
        
    }
private:
    vector<vector<int>> Matrix;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
