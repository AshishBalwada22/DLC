https://leetcode.com/problems/water-bottles-ii/submissions/1789571817/?envType=daily-question&envId=2025-10-02


class Solution {
public:

    int helper(int drinkbottle, int emptybottle, int exchangebottle){
        int option1 = 0 , option2 = 0;
        if(drinkbottle>0){
            option1 = drinkbottle + helper(0, emptybottle + drinkbottle, exchangebottle);
        }
        if(emptybottle >=exchangebottle){
            option2 = helper(drinkbottle+1, emptybottle - exchangebottle, exchangebottle+1);
        }
        return max(option1,option2);
    }
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return helper(numBottles, 0, numExchange);
    }
};