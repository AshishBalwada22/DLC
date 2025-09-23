https://leetcode.com/problems/minimum-number-of-people-to-teach/description/?envType=daily-question&envId=2025-09-10

class Solution {
public:
    bool isuserknowlang(vector<int>&lang,int l){
        for(auto val:lang){
            if(val==l) return true;
        }
        return false;
    }
    bool canCommunicate(vector<int>&l1,vector<int>&l2){
        for(int val1:l1){
            for(int val2:l2){
                if(val1==val2) return true;
            }
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // choose one language only and teach it to some user, find minimum number of user to teach

        //step1 -> find number of user which we need to teach that means can't communicate with each other
        set<int>user;// user to teach
        for(auto v:friendships){
            int user1=v[0]-1;
            int user2=v[1]-1;
            vector<int>l1=languages[user1];
            vector<int>l2=languages[user2];
            if(!canCommunicate(l1,l2)){
                user.insert(user1);
                user.insert(user2);
            }
        }
        // step2 -> traverse through each language (1->n) to teach each student
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int cnt=0; // number of user to teach
            for(auto it=user.begin();it!=user.end();it++){
                int u = *it;
                vector<int>lang=languages[u];
                if(!isuserknowlang(lang,i)){
                    cnt++;
                }
            }
            ans=min(ans,cnt);
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};