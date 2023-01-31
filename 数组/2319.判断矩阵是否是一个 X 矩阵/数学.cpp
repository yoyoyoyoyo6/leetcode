class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid.size(); ++j) {
                // 当 i == j为主对角线的元素
                // 当i + j == grid.size() - 1 时为次对角线的元素
                if(i == j || (i + j) == (grid.size() - 1)) {
                    if(grid[i][j] == 0) {
                        return false;
                    }
                }
                else if(grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
