https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/?envType=daily-question&envId=2025-09-05

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // num1-(2^i+num2)=0
        // num1 - k*(2^i+num2) = 0
        // num1 - k*(2^i) - k*num2 = 0
        // num1 - k*num2 = k*(2^i) , rhs should be represent in terms of sum of power of 2
        // k - no of operation, can be from 1 to 60
        // let x = k*(2^i)
        // 7 = 111 => 2^0 + 2^1 + 2^2 => that means 3 operation (2^i represent in terms of k times sum of 2^i)
        // operation is equivalent to number of bit set
        /*
        for(int k=1;k<=60;k++){
            long long x = num1 - 1LL*k*num2;
            if(x<0) continue; // we cannot represent -ve number in terms of bits
            int bits = __builtin_popcount(x);// number of bit set
            if(bits<=k && x>=k){// if bits <= k, then we can do bits operation as we can do max k operation
                return k; // if x < k, then we cannot represent x by doing k operation
            }
        }
        return -1;
        */
        if (num2==0) return popcount(unsigned(num1));
        long long x=num1;
        for(int k=1; k<36; k++){
            x-=num2;
            if (x<k) return -1;
            if (x>=0 && k>=popcount((unsigned long long)(x))) return k;
        }
        return -1;
    }
};