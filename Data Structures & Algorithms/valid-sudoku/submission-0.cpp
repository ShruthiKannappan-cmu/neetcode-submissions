class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for(int i = 0;i<9;i++){
            int val[9] = {0};
            for(int j = 0;j<9;j++){
                char cc =board[i][j];
                if(cc <= '9' && cc>= '1') val[cc-'1']++;
            }
            for(int k = 0;k<9;k++){
                if(val[k] > 1) return false;
            }
        }
        // // col check
        for(int i = 0;i<9;i++){
            int val[9] = {0};
            for(int j = 0;j<9;j++){
                char cc =board[j][i];
                if(cc <= '9' && cc>= '1') val[cc-'1']++;
            }
            for(int k = 0;k<9;k++){
                if(val[k] > 1) return false;
            }
        }
        for(int ii = 0 ;ii<3;ii++){
            for(int jj = 0;jj<3;jj++){
                int val[9] = {0};
                for(int i = 0;i<3;i++){
                    for(int j = 0;j<3;j++){
                        int indi= ii*3+i;
                        int indj = jj*3+j;
                        char cc =board[indi][indj];
                        if(cc <= '9' && cc>= '1') val[cc-'1']++;
                    }
                }
                for(int k = 0;k<9;k++){
                    if(val[k] > 1) return false;
                }   
            }
        }
        return true;
    }
};
