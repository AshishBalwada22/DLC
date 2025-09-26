https://leetcode.com/problems/valid-triangle-number/description/?envType=daily-question&envId=2025-09-26

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // sorting
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        // nums[j] + nums[k] > nums[i] , for valid triangle
        for(int i=n-1;i>=0;i--){
            int j=0,k=i-1;
            while(j<k){
              if(nums[j]+nums[k]>nums[i]){
                 ans+=k-j;
                 k--;
              } 
              else{
                j++;
              }
            }
        }
        return ans;
    }
};