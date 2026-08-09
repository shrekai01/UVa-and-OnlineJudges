class NumArray {
public:
    // prefix sum
    vector<int> pre_sum;
    NumArray(vector<int>& nums) {
        pre_sum.resize(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++){
            pre_sum[i + 1] = pre_sum[i] + nums[i]; // add pre_sum[0] = 0 to avoid the special case when i == 0 or nums is empty
        }
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }
    // O(n) time for initialization, where n is nums.length, O(1) time for sumRange
    // O(n) extra-space
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */