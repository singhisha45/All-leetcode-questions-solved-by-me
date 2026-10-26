class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(i == m - 1 && j == n - 1) return max(1, 1 - dungeon[i][j]);;
        if( i >= m || j >= n) return INT_MAX;

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int right = solve(i, j + 1, dungeon, dp);
        int down  = solve(i + 1, j, dungeon, dp);

        int need = min(right, down);

        return dp[i][j] = max(1, need - dungeon[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n, INT_MAX));
        int ans = solve(0,0, dungeon,dp);
        return ans;
    }
};