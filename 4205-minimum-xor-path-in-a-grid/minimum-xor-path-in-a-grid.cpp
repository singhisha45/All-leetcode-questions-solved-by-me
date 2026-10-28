class Solution {
public:

    int solve(int m, int n,int i, int j, vector<vector<int>>& grid, int curXOR,vector<vector<vector<int>>>& dp){   
        if(i >= m || j >= n) return INT_MAX;
        curXOR ^= grid[i][j];
        if(i == m - 1 && j == n - 1) return curXOR;

        if(dp[i][j][curXOR] != -1) return dp[i][j][curXOR];
        
        int right = solve(m,n,i, j+1, grid, curXOR, dp);
        int down = solve(m,n,i + 1, j, grid, curXOR, dp);

        return dp[i][j][curXOR] = min(down, right);
    }

    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp( m,vector<vector<int>>(n,
        vector<int>(1024, -1) ) );
        int ans = solve(m,n,0,0,grid,0, dp);
        return ans;
    }
};