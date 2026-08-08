class Solution {
public:
    // binary search
    // just exactly the index of lower_bound
    int lowerBound(vector<int> &arr, const int target){
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
    int searchInsert(vector<int>& nums, int target) {
        int index = lowerBound(nums, target);
        return index;
    }
    // O(n) time, O(1) extra-space
};