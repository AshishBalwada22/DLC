https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/?envType=daily-question&envId=2025-09-08

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            string st1=to_string(i);
            string st2=to_string(n-i);
            if(st1.find('0')==string::npos&&st2.find('0')==string::npos) return {i,n-i};
        }
        return {0,0};
    }
};