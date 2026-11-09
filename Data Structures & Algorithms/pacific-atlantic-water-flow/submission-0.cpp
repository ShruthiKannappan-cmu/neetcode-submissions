class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        set<pair<int,int>> pacific, atlantic;
        for(int i = 0;i<n;i++){
            pacific.insert({i,0});
            atlantic.insert({i,m-1});
        }
        for(int i = 0;i<m;i++){
            pacific.insert({0,i});
            atlantic.insert({n-1,i});
        }
        queue<pair<int,int>> q;
        vector<vector<bool>> visitedp(n, vector<bool>(m, false));
        for(auto x: pacific){
            q.push(x);
        }
        while(!q.empty()){
            auto topval = q.front();
            auto i = topval.first;
            auto j = topval.second;
            q.pop();
            visitedp[i][j] = true;
            if((i+1<n) && !visitedp[i+1][j] && heights[i+1][j] >= heights[i][j]){
                q.push({i+1,j});
                pacific.insert({i+1,j});
            }
            if((i-1>=0) && !visitedp[i-1][j] && heights[i-1][j] >= heights[i][j]){
                q.push({i-1,j});
                pacific.insert({i-1,j});
            }
            if((j+1<m) && !visitedp[i][j+1] && heights[i][j+1] >= heights[i][j]){
                q.push({i,j+1});
                pacific.insert({i,j+1});
            }
            if((j-1>=0) && !visitedp[i][j-1] && heights[i][j-1] >= heights[i][j]){
                q.push({i,j-1});
                pacific.insert({i,j-1});
            }
        }


        vector<vector<bool>> visiteda(n, vector<bool>(m, false));
        for(auto x: atlantic){
            q.push(x);
        }
        while(!q.empty()){
            auto topval = q.front();
            auto i = topval.first;
            auto j = topval.second;
            q.pop();
            visiteda[i][j] = true;
            if((i+1<n) && !visiteda[i+1][j] && heights[i+1][j] >= heights[i][j]){
                q.push({i+1,j});
                atlantic.insert({i+1,j});
            }
            if((i-1>=0) && !visiteda[i-1][j] && heights[i-1][j] >= heights[i][j]){
                q.push({i-1,j});
                atlantic.insert({i-1,j});
            }
            if((j+1<m) && !visiteda[i][j+1] && heights[i][j+1] >= heights[i][j]){
                q.push({i,j+1});
                atlantic.insert({i,j+1});
            }
            if((j-1>=0) && !visiteda[i][j-1] && heights[i][j-1] >= heights[i][j]){
                q.push({i,j-1});
                atlantic.insert({i,j-1});
            }
        }
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((pacific.count({i,j}) == 1) && (atlantic.count({i,j}) == 1)){
                    vector<int> v(2);
                    v[0] = i;
                    v[1] = j;
                    ans.push_back(v);
                }
            }
        }
        return ans;

    }
};
