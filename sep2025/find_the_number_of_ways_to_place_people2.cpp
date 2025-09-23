https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/?envType=daily-question&envId=2025-09-03

class Solution {
public:
    static bool comp(const vector<int>&p1,const vector<int>&p2){
        if(p1[0]==p2[0]) return p1[1]>p2[1];
        return p1[0]<p2[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),comp);
        int ans=0;
        for(int i=0;i<n;i++){
            int top=points[i][1];
            int bottomTillNow=INT_MIN;
            for(int j=i+1;j<n;j++){
                int ypoint=points[j][1];
                if(ypoint>bottomTillNow&&ypoint<=top){
                    ans++;
                    bottomTillNow=ypoint;
                    if(ypoint==top) break;
                }
            }
        } 
        return ans;
    }
};