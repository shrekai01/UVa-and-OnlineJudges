class Solution {
public:
    // binary search
    // only find the leftmost one(like lower_bound function in C++)
    int lowerBound(vector<int>& arr, const int target){
        int n = arr.size();
        int l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(arr[m] >= target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start_pos = lowerBound(nums, target);
        if(start_pos >= nums.size() || nums[start_pos] != target) return {-1, -1};
        int end_pos = lowerBound(nums, target + 1) - 1;
        return {start_pos, end_pos};
    }
    // O(log(n)) time, O(1) extra-space
};