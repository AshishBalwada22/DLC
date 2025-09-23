https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/?envType=daily-question&envId=2025-09-02

class Solution {
public:
    static bool comp(const vector<int>&p1, const vector<int>&p2){
        if(p1[0]==p2[0]) return p1[1]>p2[1];
        return p1[0]<p2[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        // (1,5) (2,1) (3,2) (4,3) (5,5) (6,5)  => try algorithm for 1st point
        sort(points.begin(),points.end(),comp); // sort ascending by x coordinate and descending by y coordinate(top point comes first)
        //consider each point as top left corner
        int n=points.size(), ans=0;
        for(int i=0;i<n;i++){
            int top=points[i][1];
            int bottomPointTillNow=INT_MIN;
            for(int j=i+1;j<n;j++){
                int ypoint=points[j][1];
                if(ypoint>bottomPointTillNow && ypoint<=top){
                    ans++;
                    bottomPointTillNow = ypoint;
                    if(ypoint==top) break;
                }
            }
        }
        return ans;
    }
};