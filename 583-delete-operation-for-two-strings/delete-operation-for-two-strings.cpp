class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.length(); 
        int s2 = word2.length(); 

        vector<vector<int>> dp(s1 + 1, vector<int> (s2 + 1));

        for(int i = 0; i <= s2; i++ ){
            dp[0][i] = 0;
        }

        for(int i = 0; i <= s1; i++ ){
            dp[i][0] = 0;
        }

        for(int i = 1; i <=s1; i++){
            for(int j = 1; j<= s2; j++){
                if(word1[i - 1] == word2[j -1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
        }
        }
    int lcs = dp[s1][s2];

        return (s1 - lcs) + (s2 - lcs);
    }
};