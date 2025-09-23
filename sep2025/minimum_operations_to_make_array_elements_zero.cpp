https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/?envType=daily-question&envId=2025-09-06

class Solution {
public:
    typedef long long int ll;
    long long minOperations(vector<vector<int>>& queries) {
        // power of 4
        // 4^0 -> 4^1 - 1 => [1,3] requires 1 operation to make number 0
        // 4^1 -> 4^2 - 1 => [4,15] requires 2 operation
        ll ans=0;
        for(vector<int> v : queries){
            ll a = v[0];
            ll b = v[1];
            ll curpow=1;
            ll operation=0;
            for(int power=1;power<=16;power++){ 
                ll lrange=max(a,curpow);
                ll rrange=min(b,curpow*4-1);
                curpow=curpow*4;
                if(lrange<=rrange){
                   operation+=(rrange-lrange+1)*power;
                }
            }
            ans += (operation+1)/2; // we should two division as 1 operation
        }
        return ans;
    }
};