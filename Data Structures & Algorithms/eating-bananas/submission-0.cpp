class Solution {
public:
    bool getPossibility(vector<int>& piles, int h, int k ){
        int totalHours = 0;
        for(auto x: piles){
            totalHours += (x+k-1)/k;
        }
        return (totalHours<= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = piles[0];
        for(int i = 1;i<piles.size();i++){
            maxVal = max(piles[i],maxVal);
        }
        int l = 1, r = maxVal;
        while(r-l>0 && l < maxVal && r >= 0){
            int mid = l+(r-l)/2;
            if(getPossibility(piles,h,mid)){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return r;
    }
};
