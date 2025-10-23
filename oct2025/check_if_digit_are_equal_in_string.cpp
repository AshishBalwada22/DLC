https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23

class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()!=2){
            string str="";
            for(int i=0;i<s.length()-1;i++){
                 int a = s[i]-'0';
                 int b = s[i+1]-'0';
                 str+=to_string((a+b)%10);
            } 
            s=str;
        }
        if(s[0]==s[1]) return true;
        return false;
    }
};