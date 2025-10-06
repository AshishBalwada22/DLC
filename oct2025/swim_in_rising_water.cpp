https://leetcode.com/problems/swim-in-rising-water/submissions/1793471269/?envType=daily-question&envId=2025-10-06


class Solution {
public:
    class cell{
        public : 
        int x;
        int y;
        int t; // can reach to cell in time t
        cell(int xx, int yy, int tt){
            x = xx;
            y = yy;
            t = tt;
        }
    };
    struct compare{
        bool operator()(const cell& a, const cell& b)const{
            return a.t>=b.t; // want ascending order, minimum pq
        } 
    };
    int swimInWater(vector<vector<int>>& grid) {
        // similar to djkstra
        // can reach adjacent within time = max(cur,neighbourtime)
        int n = grid.size();
        priority_queue<cell,vector<cell>,compare>pq;
        vector<vector<int>>visited(n,vector<int>(n,0));
        int dx[4]= {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        pq.push(cell(0,0,grid[0][0]));
        while(!pq.empty()){
            cell temp = pq.top();
            pq.pop();
            int r = temp.x;
            int c = temp.y;
            int t = temp.t;
            if(r==n-1&&c==n-1) return t;
            visited[r][c] = 1; // this is my shortest time to go via (r,c)
            for(int k=0;k<4;k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&!visited[nr][nc]){
                    pq.push(cell(nr,nc,max(t,grid[nr][nc])));
                }
            }
        }
        return -1;
    }
};