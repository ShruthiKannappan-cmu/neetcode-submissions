class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = size(nums);
        vector<int> ans;
        int nums_copy[n];
        for(int i = 0;i<n;i++){
            nums_copy[i] = nums[i];
        }
        sort(nums_copy,nums_copy+n);
        int l = 0, r = n-1;
        int x , y;
        while(r-l>1){
            int cur_sum = nums_copy[l]+nums_copy[r];
            if(cur_sum<target){
                l++;
            } else if(cur_sum>target){
                r--;
            } else {
                break;
            }
        }
        if(nums_copy[r]+nums_copy[l] != target){
            return ans;
        }
        x = nums_copy[l];
        y = nums_copy[r];
        int a = -1, b = -1;
        for(int i = 0;i<n;i++){
            if(a == -1){
                if((nums[i]==x))
                {
                    a = i;
                    continue;
                }
            } 
            if(b==-1){
                if((nums[i]==y))
                {
                    b = i;
                }
            }
        }
        ans.push_back(min(a,b));
        ans.push_back(max(a,b));
        return ans;
    }
};
