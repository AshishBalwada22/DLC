https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans=0;
        for(int val:nums){
            if(val%2==0) ans=ans|val;
        }
        return ans;
    }
};