class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,vector<int>(k+1,INT_MAX)));
        dist[0][0][0]=0;
        priority_queue<
            pair<pair<int,int>, pair<int,int>>,
            vector<pair<pair<int,int>, pair<int,int>>>,
            greater<pair<pair<int,int>, pair<int,int>>>
        > pq;
        pq.push({{0,0},{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1){
                return it.first.first;
            }
            int stops = it.first.second;
            vector<int> a = {1,-1,0,0};
            vector<int> b={0,0,1,-1};
            for(int i = 0 ; i<4 ; i++){
                if(r+a[i]<0 || c+b[i]<0 || r+a[i]>=n || c+b[i]>=m) continue;
                if(grid[r+a[i]][c+b[i]]==1){
                    if(stops<k){
                        if(dist[r+a[i]][c+b[i]][stops+1]>dist[r][c][stops]+1){
                            int val = dist[r+a[i]][c+b[i]][stops+1]=dist[r][c][stops]+1;
                            pq.push({{val,stops+1},{r+a[i],c+b[i]}});
                        }
                    }
                }
                else{
                    if(dist[r+a[i]][c+b[i]][stops]>dist[r][c][stops]+1){
                            int val = dist[r+a[i]][c+b[i]][stops]=dist[r][c][stops]+1;
                            pq.push({{val,stops},{r+a[i],c+b[i]}});
                    }    
                }

            }

        }

        
        return -1;

        
    }
};