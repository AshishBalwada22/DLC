https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2025-10-01

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n=numBottles;
        int m=numExchange;
        int ans = n;
        int nextemptybottles = n;
        while(nextemptybottles>=m){
            ans+=nextemptybottles/m;
            nextemptybottles = nextemptybottles/m + nextemptybottles%m;
        }
        return ans;
    }
};