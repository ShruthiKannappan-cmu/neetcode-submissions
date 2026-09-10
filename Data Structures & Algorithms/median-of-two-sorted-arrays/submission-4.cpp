class Solution {
public:
    pair<int,int> find_range(vector<int>& nums, int target){
        int l1 = 0, r1 = nums.size()-1;
        if(target < nums[l1]) return {-1,l1};
        if(target > nums[r1]) return {-1,r1+1};
        int lind = -1 , rind = -1;
        while((r1-l1)>0 && (r1>=0) && (l1<nums.size())){
            int mid = l1 + (r1-l1)/2;
            if(nums[mid] < target){
                l1 = mid+1;
            } else if(nums[mid] > target){
                r1 = mid-1;
            } else if(nums[mid] == target){
                lind = mid;
                rind = mid;
                break;
            }
        }

        if(lind!= -1 && (rind!=-1)){
            while((rind < nums.size()) && nums[rind] == target) rind++;
            rind--;
            while((lind >=0 )&& (nums[lind] == target)) lind--;
            lind++;
        } else {
                    if(r1>= 0 && l1<nums.size()) {
            if(nums[r1]== target){
                lind = r1;
                rind = r1;
            } else if(nums[r1]>target){
                lind = -1;
                rind = r1;
            } else if(nums[r1]<target){
                lind = -1;
                rind = r1+1;
            }
        }
        }
        return {lind,rind};
    }
    pair<int,int> cur_range(vector<int>nums, int ind){
        pair<int,int> res ;
        res.first = ind;
        res.second = ind;
        int target = nums[ind];
        while(res.second < nums.size() && (nums[res.second] == target)) res.second++;
        res.second--;
        while(res.first >= 0 && (nums[res.first] == target)) res.first--;
        res.first++;
        return res;
    }
    pair<double, bool> find_ind1(int ind,vector<int>& nums1, vector<int>& nums2 ){
        int n1 = nums1.size();
        int r1 = n1-1, l1 = 0;
        while((r1-l1>0) && (r1>=0) && (l1<n1)){
            int mid = l1 + (r1-l1)/2;
            auto range2 = find_range(nums2,nums1[mid]);
            auto range1 = cur_range(nums1,mid);
            cout<<"mid "<<mid<<endl;
            cout<<"range1 "<<range1.first<<" "<<range1.second<<endl;
            cout<<"range2 "<<range2.first<<" "<<range2.second<<endl;
            if(range2.first == -1){
                int lower_range = range1.first + range2.second;
                int higher_range = range1.second + range2.second ;
                if((ind <= higher_range) && (ind>= lower_range)) return {nums1[mid],true};
                else if(ind > higher_range){
                    l1 = mid+1;
                } else if(ind < lower_range){
                    r1 = mid-1;
                }
            } else {
                int lower_range = max(range1.first-1,0) + max(range2.first-1,0)  ;
                if(lower_range > 0 ) lower_range++;
                int higher_range = lower_range + (range1.second - range1.first) + (range2.second-range2.first) +1 ;
                if((ind <= higher_range) && (ind>= lower_range)) return {nums1[mid],true};
                else if(ind > higher_range){
                    l1 = mid+1;
                } else if(ind < lower_range){
                    r1 = mid-1;
                }
            }
        }
        if(r1!=l1) return {-1,false};
        auto range2 = find_range(nums2,nums1[r1]);
            auto range1 = cur_range(nums1,r1);
            if(range2.first == -1){
                int lower_range = range1.first + range2.second;
                int higher_range = range1.second + range2.second;
                if((ind <= higher_range) && (ind>= lower_range)) return {nums1[r1],true};
                else {
                    return {-1,false};
                }
            } else {
                int lower_range = range1.first + range2.first;
                int higher_range = range1.second + range2.second;
                if((ind <= higher_range) && (ind>= lower_range)) return {nums1[r1],true};
                else {
                    return {-1,false};
                }
            }
            return {-1,false};
    }
    double find_ind(int ind,vector<int>& nums1, vector<int>& nums2 ){
        auto res1 = find_ind1(ind,nums1,nums2 );
        cout<<"ind "<<ind<<" res1 "<<res1.first<<" "<<res1.second<<endl;
        if(res1.second) return res1.first;
        auto res2 = find_ind1(ind,nums2,nums1 );
        if(res2.second) return res2.first;
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m==0) return findSingleArrayMedian(nums2);
        if(n==0) return findSingleArrayMedian(nums1);
        if((m+n)%2 == 1) {
            return (find_ind((m+n)/2,nums1,nums2 ));
        } else {
            return ((find_ind((m+n)/2,nums1,nums2 ))+(find_ind(((m+n)/2)-1,nums1,nums2)))/2;
        }
    }
    double find_ind_single_arrary(int ind,vector<int>& nums1){
        int n1 = nums1.size();
        int r1 = n1-1, l1 = 0;
        while((r1-l1>0) && (r1>=0) && (l1<n1)){
            int mid = l1 + (r1-l1)/2;
            auto range1 = cur_range(nums1,mid);
            int lower_range = range1.first ;
            int higher_range = range1.second;
            if((ind <= higher_range) && (ind>= lower_range)) return nums1[mid];
                else if(ind > higher_range){
                    l1 = mid+1;
                } else if(ind < lower_range){
                    r1 = mid-1;
                }
            }
        
        if(r1 < 0 || l1>= n1) return 0.0;
        auto range1 = cur_range(nums1,r1);
            int lower_range = range1.first ;
            int higher_range = range1.second;
        if((ind <= higher_range) && (ind>= lower_range)) return nums1[r1];
            return 0.0;
    }

    double findSingleArrayMedian(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
         if(n%2 == 1){
            return find_ind_single_arrary((n)/2, nums);
        } else{
            return (find_ind_single_arrary((n)/2, nums)+ find_ind_single_arrary((n)/2-1, nums))/2;
        }
    }
};
