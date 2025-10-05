https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/1791822499/?envType=daily-question&envId=2025-10-05

class Solution {
public:

    void bfs(queue<pair<int,int>>&q, vector<vector<int>>&heights, vector<vector<int>>&visited){
        int n=heights.size();
        int m=heights[0].size();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            for(int k=0;k<4;k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!visited[nr][nc]&&heights[nr][nc]>=heights[r][c]){ // water need to from high to low toward ocean
                   q.push({nr,nc});
                   visited[nr][nc]=1;
                } 
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> ans;
        queue<pair<int,int>>q1;
        queue<pair<int,int>>q2;
        vector<vector<int>>visited1(n,vector<int>(m,0));
        vector<vector<int>>visited2(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0){
                    q1.push({i,j});
                    visited1[i][j]=1;
                }
                if(i==n-1||j==m-1){
                    q2.push({i,j});
                    visited2[i][j]=1;
                }
            }
        }
        bfs(q1,heights,visited1);
        bfs(q2,heights,visited2);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited1[i][j]==1 && visited2[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};