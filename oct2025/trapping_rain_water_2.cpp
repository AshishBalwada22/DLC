https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-10-03


class Solution {
public:
    class cell{
       public:
       int h;
       int r;
       int c;
       cell(int height, int row, int col){
        h = height;
        r = row;
        c = col;
       }
    };
    class compare{
        public:
        bool operator()(const cell &c1, const cell &c2) const{
            return c1.h>=c2.h; // increasing in case of priority queue
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        // store water on any particular position (i,j) not only depends upon neighbouring adjacent node but also neighbours to neighbours
        // boundaries position will not hold water.
        // also we should start from minimum height of cell as water will from that way first
        int n=heightMap.size();
        int m=heightMap[0].size();
        priority_queue<cell,vector<cell>,compare>pq;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    pq.push(cell(heightMap[i][j],i,j));
                    visited[i][j]=1;
                }
            }
        }

        int water = 0;
        int maxheight = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int height = temp.h;
            int row = temp.r;
            int col = temp.c;
            maxheight = max(maxheight, height); // maintaining max height till neighbouring node , ab tak ki max height kya hai
            for(int k=0;k<4;k++){
                int nrow = row + dx[k];
                int ncol = col + dy[k];
                if(nrow>=0&&nrow<n&ncol>=0&&ncol<m&&!visited[nrow][ncol]){
                    int curheight = heightMap[nrow][ncol];
                    if(curheight<maxheight){
                        cout << nrow <<" "<<ncol<<" "<<curheight<<" "<<maxheight<<endl;
                        water += (maxheight - curheight);
                    } 
                    pq.push(cell(curheight,nrow,ncol));
                    visited[nrow][ncol]=1;
                }
            }
            
        }
        return water;
    }
};