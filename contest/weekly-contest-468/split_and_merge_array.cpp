https://leetcode.com/problems/split-and-merge-array-transformation/description/

class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        queue<pair<vector<int>,int>>q;
        set<vector<int>>visited;
        q.push({nums1,0});
        visited.insert(nums1);
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            nums1=t.first;
            int step = t.second;
            if(nums1==nums2) return step;
            for(int l=0;l<n;l++){
            for(int r=l;r<n;r++){
                vector<int>mid(nums1.begin()+l,nums1.begin()+r+1);
                vector<int>remain;
                remain.insert(remain.end(), nums1.begin(), nums1.begin() + l);
                remain.insert(remain.end(), nums1.begin() + r + 1, nums1.end());
                for(int ind=0;ind<=remain.size();ind++){
                    vector<int>next=remain;
                    next.insert(next.begin()+ind,mid.begin(),mid.end());
                    if (visited.find(next)==visited.end()) {
                        visited.insert(next);
                        q.push({next, step + 1});
                    }
                }
            }
            }
        }
        return -1;
    }
};