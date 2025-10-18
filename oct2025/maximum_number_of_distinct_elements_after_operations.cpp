https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/?envType=daily-question&envId=2025-10-18


class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        //greedy - we would assign minimum value as much as possible within range
        sort(nums.begin(),nums.end());
        int ans=0;
        int cur = INT_MIN;
        for(int val:nums){
            int low = val-k;
            int high = val+k;
            if(cur+1<=high){
                int assigned = max(cur+1,low);
                cur = assigned;
                ans+=1;
            }
        }
        return ans;
    }
};