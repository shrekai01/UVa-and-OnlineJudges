class Solution {
public:
    // sliding window, hash table
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> ump;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ump[nums[i]]++;
            int left = i - k + 1;
            if(left < 0) continue;

            if(ump.size() >= m){
                ans = max(ans, sum);
            }

            sum -= nums[left];
            ump[nums[left]]--; if(!ump[nums[left]]) ump.erase(nums[left]);
        }
        return ans;
    }
    // O(n) time, O(k) extra-space, where n is nums.length and U is max(nums)
};