class Solution {
    vector<vector<int>> grid;
    int n, m;
    int gold = 0;
public:

    int delX[4] = {0, -1, 0, 1};
    int delY[4] = {-1, 0, 1, 0};

    bool isSafe(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void helper(int i, int j, vector<vector<bool>> &vis, int val){
        vis[i][j] = true;
        gold = max(val, gold);
        for(int k = 0; k < 4; k++){
            int x = i + delX[k];
            int y = j + delY[k];
            if(isSafe(x, y) && !vis[x][y] && grid[x][y] > 0){
                helper(x, y, vis, val + grid[x][y]);
            }
        }
        vis[i][j] = false;
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    helper(i, j, vis, grid[i][j]);
                }
            }
        }
        return gold;
    }
};