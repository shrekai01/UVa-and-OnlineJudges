class Solution {
public:
    // hash table
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cnt.contains(nums[i])) res += cnt[nums[i]];
            cnt[nums[i]]++;
        }
        return res;
    }
    // O(n) time, O(n) extra-space, where n is nums.length
};