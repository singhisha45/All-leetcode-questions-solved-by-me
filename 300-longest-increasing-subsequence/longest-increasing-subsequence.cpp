class Solution {
public:

    int lis(int idx, int p_idx, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(idx >= n) return 0;

        if(dp[idx][p_idx + 1] != -1) return dp[idx][p_idx + 1];

        int skip = lis(idx + 1, p_idx, nums, dp);
        int take = 0;
        if(p_idx == -1 || nums[idx] > nums[p_idx]){
            take = 1 + lis(idx + 1, idx, nums, dp);
        }

        int ans = max(take, skip);
        return dp[idx][p_idx + 1] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return lis(0,-1, nums, dp);
    }
};