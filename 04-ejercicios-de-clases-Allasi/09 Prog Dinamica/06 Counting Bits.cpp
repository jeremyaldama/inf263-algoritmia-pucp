//https://leetcode.com/problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int n) {
        //array de tamaño n+1 inicializado en 0
        vector<int> dp(n+1, 0);
        dp[0] = 0;

        for (int i=1; i<n+1; i++){
            dp[i] = dp[i>>1] + (i&1==1? 1:0);
        }

        return dp;
    }
};