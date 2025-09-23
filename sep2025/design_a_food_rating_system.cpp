https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2025-09-17

class FoodRatings {
public:
    unordered_map<string,int>foodtorate;// food, rate
    unordered_map<string,set<pair<int,string>>>cuisinetofood; // cuisine, food list
    unordered_map<string,string>foodtocuisine; //food , cuisine
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodtorate[foods[i]]=ratings[i];
            cuisinetofood[cuisines[i]].insert({-ratings[i],foods[i]});// sorted in decreasing order
            foodtocuisine[foods[i]]=cuisines[i]; 
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldrating = foodtorate[food];
        foodtorate[food]=newRating;
        string cuisine = foodtocuisine[food];
        cuisinetofood[cuisine].erase({-oldrating,food});
        cuisinetofood[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return cuisinetofood[cuisine].begin()->second;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */