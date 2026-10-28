class Solution {
public:
    int minInsertions(string s) {
        int n = s.length(); 
        string s2 = s;
        reverse(s2.begin(), s2.end());


        vector<vector<int>> dp(n + 1, vector<int> (n + 1));

        for(int i = 0; i <= n; i++ ){
            dp[0][i] = 0;
        }

        for(int i = 0; i <= n; i++ ){
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= n; j++){
                if(s[i - 1] == s2[j -1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
        }
        }
    int lcs = dp[n][n];

    return n - lcs;
    }
};