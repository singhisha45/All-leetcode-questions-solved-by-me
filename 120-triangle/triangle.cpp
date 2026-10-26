class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        
        if(i == triangle.size() - 1) return triangle[i][j];

        if(dp[i][j] !=  INT_MIN) return dp[i][j];

        int down = solve(i + 1, j, triangle, dp);
        int downright = solve(i + 1, j + 1, triangle, dp);
        
        return dp[i][j] = triangle[i][j] + min(downright,down);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        int ans = solve(0,0, triangle,dp);
        return ans;
    }
};