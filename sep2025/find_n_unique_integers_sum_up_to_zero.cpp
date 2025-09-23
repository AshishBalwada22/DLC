https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07

class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) return {0};
        vector<int>ans;
        int num=1;
        while(n!=0&&n!=1){
            ans.push_back(num);
            ans.push_back(-1*num);
            num++;
            n=n-2;
        }
        if(n==1) ans.push_back(0);
        return ans;
    }
};