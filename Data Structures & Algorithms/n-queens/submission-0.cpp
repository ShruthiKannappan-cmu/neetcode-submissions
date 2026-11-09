class Solution {
public:
    void solveNQueensRec(vector<int> &rows, int n, vector<bool>&cols, set<int> &sums, set<int> &diffs,  vector<vector<string>>&ans){
        int row = rows.size();
        if(row == n){
            vector<string> v;
            for(int i = 0;i<n;i++){
                int col = rows[i];
                string cur_string = "";
                for(int j = 0;j<n;j++){
                    if(j==col){
                        cur_string += "Q";
                    } else {
                        cur_string += ".";
                    }
                }
                v.push_back(cur_string);
            }
            ans.push_back(v);
            return;
        }

        for(int i = 0;i<n;i++){
            if(cols[i]) continue;
            if(sums.count(i+row)) continue;
            if(diffs.count(i-row)) continue;
            cols[i] = true;
            sums.insert(i+row);
            diffs.insert(i-row);
            rows.push_back(i);
            solveNQueensRec(rows, n, cols, sums, diffs, ans);
            cols[i] = false;
            sums.erase(i+row);
            diffs.erase(i-row);
            rows.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> rows; vector<bool>cols(n,false); set<int> sums; set<int> diffs;
        solveNQueensRec(rows,n,cols,sums,diffs,ans);
        return ans;
    }
};
