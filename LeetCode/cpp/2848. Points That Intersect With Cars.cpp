class Solution {
public:
    // difference array
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        int max_end = ranges::max(nums, {}, [](const auto &a){return a[1];})[1];
        vector<int> diff(max_end + 2);
        for(int i = 0; i < n; i++){
            diff[nums[i][0]]++;
            diff[nums[i][1] + 1]--;
        }
        int cnt = 0, s = 0;
        for(int d : diff){
            s += d;
            cnt += s > 0;
        }
        return cnt;
    }
    // O(n + U) time, O(U) extra-space, where n is nums.length and U is max_end
};