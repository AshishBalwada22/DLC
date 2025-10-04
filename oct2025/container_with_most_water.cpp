https://leetcode.com/problems/container-with-most-water/description/?envType=daily-question&envId=2025-10-04


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ans=0;
        for(;l<=r;){
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<=height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};