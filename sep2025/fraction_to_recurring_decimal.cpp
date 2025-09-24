https://leetcode.com/problems/fraction-to-recurring-decimal/description/?envType=daily-question&envId=2025-09-24

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        long num = numerator, deno = denominator;
        if(num == 0) return "0";
        if(num<0 && deno>0){
            ans+="-";
            num = abs(num);
        }
        if(num>0 && deno<0){
            ans+="-";
            deno = abs(deno);
        }
        if(num<0 && deno<0){
            num = abs(num);
            deno = abs(deno);
        }
        // case 1 -> completely divisible
        long q = num/deno;
        long r = num%deno;
        ans+=to_string(q);
        if(r==0) return ans;
        ans+=".";
        unordered_map<int,int>m;//remainder, position
        while(r!=0){
          if(m.find(r)!=m.end()){
            int pos = m[r];
            ans.insert(pos,"(");
            ans+=")";
            break;
          }else{
            m[r]=ans.length();
            r=r*10;// like how we divide in fraction
            q=r/deno;
            r=r%deno;
            ans+=to_string(q);
          }
        }
        return ans;
    }
};