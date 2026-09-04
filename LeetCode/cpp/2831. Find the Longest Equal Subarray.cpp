class Solution {
public:
    // (pos[right] - pos[left] + 1) - (right - left + 1)
    // => (pos[right] - pos[left]) - (right - left)
    // => (pos[right] - right) - (pos[left] - left)

    // sliding window
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> pos_lists(n + 1);
        for(int i = 0; i < n; i++){
            int x = nums[i];
            pos_lists[x].push_back(i - pos_lists[x].size()); // to simplify the calculation
        }
        int ans = 0;
        for(vector<int> &pos : pos_lists){
            int left = 0;
            for(int right = 0; right < pos.size(); right++){
                while(pos[right] - pos[left] > k){
                    left++;
                }
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
    // O(n) time, O(n) extra-space, where n is nums.length
};