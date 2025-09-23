https://leetcode.com/problems/vowels-game-in-a-string/?envType=daily-question&envId=2025-09-12

class Solution {
public:
    bool doesAliceWin(string s) {
        // alice will win if we have odd number of vowel -> remove all vowel at once
        // alice will win if we have even number of vowel -> i.e 4 -> 3(alice) + 0(bob) + alice(1)
        int cnt=0;
        for(char ch:s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') cnt++;
        }
        if(cnt==0) return false;// alice will loose the game
        return true;// in all other case alice will win the game
    }
};