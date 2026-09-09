class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(r-l>0 && r>= 0 && l<nums.size()){
            int mid = l+ (r-l)/2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid]<target){
                l = mid+1;
            } else if(nums[mid]>target){
                r = mid-1;
            }
        }
        if(r < nums.size() && r>=0 && nums[r] == target) return r;
        return -1;
    }
};
