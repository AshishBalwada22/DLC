https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question&envId=2025-09-01

class Solution {
public:
    struct comp{
    bool operator()(pair<int,int>&p1,pair<int,int>&p2){
        double diff1=(double)(p1.first+1)/(p1.second+1) - (double)p1.first/p1.second;
        double diff2=(double)(p2.first+1)/(p2.second+1) - (double)p2.first/p2.second;
        return diff2>diff1;
    }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Assign extra student to that class which has biggest impact in ratio
        // [2,4] impact = (2+1)/(4+1) - 2/4
        // take max heap, greedy
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(auto v:classes) pq.push({v[0],v[1]});
        while(extraStudents--){
            auto t=pq.top();
            pq.pop();
            t.first++;
            t.second++;
            pq.push({t.first,t.second});
        } 
        double ans=0;
        int size=pq.size();
        while(!pq.empty()){
            auto p=pq.top();
            ans+=(double)p.first/p.second;
            pq.pop();
        }
        ans=ans/size;
        return ans;
    }
};