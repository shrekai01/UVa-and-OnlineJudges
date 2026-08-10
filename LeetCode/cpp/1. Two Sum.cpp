class Solution {
public:
    // hash table
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for(int i = 0; i < nums.size(); i++){
            if(ht.contains(target - nums[i])) return {ht[target - nums[i]], i};
            ht[nums[i]] = i;
        }
        return {-1, -1};
    }
    // O(n) time, O(n) extra-space, where n is nums.length
};