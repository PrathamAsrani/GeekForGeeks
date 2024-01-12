class Solution {
public:
    int delX[4] = {0, -1, 0, 1};
    int delY[4] = {-1, 0, 1, 0};
    bool isSafe(int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(int i, int j, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp, vector<vector<bool>> &vis){
        vis[i][j] = true;
        int cnt = 1;
        for(int k = 0; k < 4; k++){
            int x = i+delX[k];
            int y = j+delY[k];
            if(isSafe(x, y, n, m) && mat[i][j] < mat[x][y]){
                if(!vis[x][y]) 
                    dfs(x, y, n, m, mat, dp, vis);
                int tmp = 1;
                tmp = tmp+dp[x][y];
                cnt = max(cnt, tmp);
            }
        }
        dp[i][j] = cnt;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = -1;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i, j, n, m, mat, dp, vis);
                ans = max(ans, dp[i][j]);
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return ans;
    }
};