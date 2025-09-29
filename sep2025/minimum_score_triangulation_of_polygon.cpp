https://leetcode.com/problems/minimum-score-triangulation-of-polygon/submissions/1786568994/?envType=daily-question&envId=2025-09-29

class Solution {
public:
    int helper(int i, int j, vector<int>&values, vector<vector<int>>&dp){
        if(i+1==j) return 0;// that means only two points we have, can not form a triangle
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,values[i]*values[j]*values[k]+helper(i,k,values,dp)+helper(k,j,values,dp));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        // pick any side with two points, then we have n-2 point remain - can form n-2 triangles
        // if we pick a side(i,j) and pick kth point, then it divides the polygon into two sub polygon
        // can take (i,k) and (j,k) as side in sub-polygon
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,n-1,values,dp);
    }
};