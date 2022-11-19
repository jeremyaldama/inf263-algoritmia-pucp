//https://leetcode.com/problems/pascals-triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        
        dp[0].resize(1);
        dp[0][0] = 1;
        
        if (numRows>1){
            dp[1].resize(2);
            dp[1][0] = 1;
            dp[1][1] = 1;
        }

        int rows = 2;
        for (int i=2; i<numRows; i++){
            
            rows++;
            dp[i].resize(rows);
            dp[i][0] = 1;
            dp[i][rows-1] = 1;

            for (int j=1; j<rows-1; j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        return dp; 
    }
};