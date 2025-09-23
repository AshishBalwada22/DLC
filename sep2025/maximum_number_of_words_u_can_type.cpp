https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=daily-question&envId=2025-09-15

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int>freq(26,0);
        for(char ch:brokenLetters){
            freq[ch-'a']=1;
        }
        stringstream ss(text);
        string word;
        int ans=0;
        while(ss>>word){
            int flag=true;
            for(char ch:word){
                if(freq[ch-'a']) flag=false;
            }
            if(flag) ans++;
        }
        return ans;
    }
};