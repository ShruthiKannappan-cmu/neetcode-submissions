class Solution {
public:
        int dfs(vector<vector<bool>>& visited, vector<vector<int>>& grid, int i , int j ,int n,  int m){
        visited[i][j] = true;
        int cnt = 1;
        if(i-1>=0){
            if(grid[i-1][j] == 1){
                if(!visited[i-1][j]){
                    cnt+= dfs(visited, grid, i-1,j,n,m);
                }
            }
        }
        if(j-1>=0){
            if(grid[i][j-1] == 1){
                if(!visited[i][j-1]){
                    cnt+=dfs(visited, grid, i,j-1,n,m);
                }
            }
        }

        if(i+1<n){
            if(grid[i+1][j] == 1){
                if(!visited[i+1][j]){
                   cnt+= dfs(visited, grid, i+1,j,n,m);
                }
            }
        }
        if(j+1<m){
            if(grid[i][j+1] == 1){
                if(!visited[i][j+1]){
                   cnt+= dfs(visited, grid, i,j+1,n,m);
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> visited;
        for(int j = 0;j<n;j++){
            vector<bool> v(m);
            for(int i = 0;i<m;i++) v[i] = false;
           visited.push_back(v);
        }
    
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0) continue;
                if(visited[i][j]) continue;
                
                cnt = max(cnt,dfs(visited,grid,i,j,n,m));
            }
        }   
        return cnt;
    }
};
