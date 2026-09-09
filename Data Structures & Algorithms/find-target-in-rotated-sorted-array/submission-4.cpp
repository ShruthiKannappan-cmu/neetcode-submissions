class Solution {
public:
    int binary_search_for_target(int target,vector<int>& nums, int l, int r){
        int ll = l, rr = r;
        while((rr-ll)>0 && rr>=l && ll<=r){
            int mid = ll + (rr-ll)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]<target) {
                ll = mid+1;
            } else {
                rr = mid-1;
            }
        }
        if(rr>= l && ll <= r){
            if(nums[rr] == target) return rr;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r= n-1;
        if(nums[r] == target) return r;
        if(nums[l] == target ) return l;
        int lval = nums[l];
        int rval = nums[r];
        if(nums[r] > nums[l]) return binary_search_for_target(target,nums,l,r);

        int rr = n-2;
        int ll = 0;
        int maxInd = -1;
        while(rr-ll >0  && (rr>=0) && (ll<n-1)){
            int mid = ll + (rr-ll)/2;
            if(nums[mid+1] < nums[mid]){
                maxInd = mid;
                break;
            } else if (nums[mid] < nums[rr]){
                rr = mid;
            } else if(nums[mid] > nums[ll]){
                ll = mid+1;
            }
        }
        if(ll < n-1 && rr>=0){
            if(nums[ll] > nums[ll+1]) maxInd = ll;
        }
        cout<<maxInd<<endl;
        if(nums[l] < target){
            // FIRST HALF
            return binary_search_for_target(target,nums,l,maxInd);

        } else {
            return binary_search_for_target(target,nums,maxInd+1,r);
        }
    }
};
