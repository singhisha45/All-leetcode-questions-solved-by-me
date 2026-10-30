class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        vector<int> count(n + 1, 1);

        int max = 1;
        int ans = 0;

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(nums[i] < nums[j] && dp[i] < 1 + dp[j]){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if(nums[i] < nums[j] && dp[i] == 1 + dp[j]){
                    count[i] += count[j];
                }
                if(max < dp[i]){
                    max = dp[i];
                }
            }
        }
      
        for(int i = 0; i < n; i++){
            if(dp[i] == max){
                ans = ans + count[i];
            }
        }
        
        return ans;
    }
};