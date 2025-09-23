https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff1= abs(x-z);
        int diff2= abs(y-z);
        if(diff1<diff2) return 1;
        else if(diff2<diff1) return 2;
        return 0;
    }
};