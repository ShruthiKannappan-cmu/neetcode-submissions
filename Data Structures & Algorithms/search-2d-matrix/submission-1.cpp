class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int li = 0, ri = n-1;
        int r = 0;
        while(ri-li > 0 && li< n && ri>= 0){
            int midi = li + (ri-li)/2;
            if(matrix[midi][0] == target) return true;
            else if(matrix[midi][0] < target){
                if(midi + 1 < n ){
                    if(matrix[midi+1][0] == target){
                        return true;
                    } else if(matrix[midi+1][0] > target){
                        r = midi;
                        break;
                    } else {
                        li = midi+1;
                    }
                } else {
                    r = midi ;
                    break;
                }
            } else if(matrix[midi][0] > target){
                ri = midi -1;
            }
        }
        if(li == ri){
            if(matrix[li][0] < target){
                if(li+1<n){
                    if(matrix[li+1][0] > target){
                        r = li;
                    } else {
                        r = li+1;
                    }
                } else {
                    r = li;
                }
            }

        }
        int lj = 0, rj = m-1;
        int c = 0;
        cout<<r<<endl;
        while(rj-lj > 0 && lj< m && rj>= 0){
            int midj = lj + (rj-lj)/2;
            if(matrix[r][midj] == target) return true;
            else if(matrix[r][midj] < target){
                lj = midj+1 ;
            } else if(matrix[r][midj] > target){
                rj = midj -1;
            }
        }
        if(matrix[r][lj] == target) return true;
        return false;

        
    }
};
