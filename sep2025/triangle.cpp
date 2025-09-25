https://leetcode.com/problems/triangle/description/?envType=daily-question&envId=2025-09-25

class Solution {
public:
    // recursive top to bottom, but starting position -> fixed, destination -> not fixed
    int helper(int i, int j, vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==triangle.size()-1){
           return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int option1 = helper(i+1,j,triangle,dp);
        int option2 = helper(i+1,j+1,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(option1,option2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        //vector<vector<int>>dp(n,vector<int>(n,-1));
        //return helper(0,0,triangle,dp);
        // tabulation method
        // n-1 -> 0 
        vector<vector<int>>dp(n,vector<int>(n,0));
        // base case
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j] = triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};