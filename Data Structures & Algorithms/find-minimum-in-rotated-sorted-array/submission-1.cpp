class Solution {
public:
    int findMin(vector<int> &nums) {
        // if l > r -- min in between / rotation happened.
        // else if l < r--> l is minimum 
        // if mid > l l --> mid 
        // if mid < r  r--> mid 4 5 6 1 22 3
        int l = 0, r = nums.size()-1;
        int lval = nums[l];
        int rval = nums[r];
        if(r==0) return nums[r];
        if(nums[l] < nums[r]) return nums[l];
        if(nums[r-1]>nums[r]) return nums[r];
        l = 1;
        r = nums.size()-2;
        while(r-l> 0 && r>=1  && l < nums.size()-2){
            int mid = l + (r-l)/2;
            // cout<<l<<" "<<mid<<" "<<r<<endl;
            if(nums[mid+1] < nums[mid]){
                return nums[mid+1];
            } else {
                // mid + 1 > mid
                if(nums[mid-1] > nums[mid]){
                    return nums[mid];
                } else {
                    // mid-1< mid< mid+1
                    if(nums[mid] < rval){
                        r = mid-1;
                    } else if(nums[mid] > lval){
                        l = mid+1;
                    }
                }
            }
        }   
        if(nums[r] < nums[r-1] )
        return nums[r];
        if(nums[r+1]<nums[r]) return nums[r+1];
        return nums[r];
    }
};
