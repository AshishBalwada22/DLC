https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16

class Solution {
public:
    //euclidean algorithm
    int gcdd(int a, int b){
        if(a<b) return gcdd(b,a);
        if(b==0) return a;
        return gcdd(b,a%b);
    }
    int lcmm(int a, int b){
        if(a==0||b==0) return 0;
        return (1LL*a)/gcd(a,b)*b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(nums[i]);
            while(st.size()>=2){
                int top1=st.top();
                st.pop();
                int top2=st.top();
                int gcd = gcdd(top2,top1);
                if(gcd==1){
                    st.push(top1);
                    break;
                }
                st.pop();
                int lcm = lcmm(top2,top1);
                st.push(lcm);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};