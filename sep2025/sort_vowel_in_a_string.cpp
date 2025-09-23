https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2025-09-11

class Solution {
public:
    bool isVowel(char ch){
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true; 
        return false;
    }

    string sortVowels(string s) {
        vector<char>vowel;
        for(char ch:s){
            if(isVowel(ch)){
                vowel.push_back(ch);
            }
        }
        sort(vowel.begin(),vowel.end());
        int k=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=vowel[k++];
            }
        }
        return s;
    }
};