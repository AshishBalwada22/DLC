https://leetcode.com/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-10-07


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int,int>m;// lake no. -> index
        vector<int>dryindex;
        int n=rains.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
          int lake = rains[i]; // lake no.
          if(lake==0){
            dryindex.push_back(i);
            ans[i] = 1; // in case, if we have dry lake operation, but no lake is present for dry
          }
          else{
             if(m.find(lake)==m.end()){ // fill the lake
                m[lake]=i; 
                ans[i]=-1;
             }else{ // already fill -> empty previous one and fill again
                int lakeindex = m[lake];
                auto dryindaddress = upper_bound(dryindex.begin(),dryindex.end(),lakeindex);
                int ind = dryindaddress - dryindex.begin();
                if(ind == dryindex.size()) return {};
                ans[dryindex[ind]] = lake;
                dryindex.erase(dryindaddress);
                ans[i] = -1;
                m[lake] = i;
             }
          }
        }
        return ans;
    }
};