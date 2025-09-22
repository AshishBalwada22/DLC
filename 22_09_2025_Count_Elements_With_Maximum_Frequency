class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(101,0);
        for(auto val:nums) freq[val]++;
        int maxi=0,ans=0;
        for(int val:freq){
            if(val>maxi){
                maxi=val;
                ans = val;
            }else if(val==maxi) ans+=val;
        }
        return ans;
    }
};