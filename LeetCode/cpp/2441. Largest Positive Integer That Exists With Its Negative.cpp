class Solution {
public:
    // hash table
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int mx = -1;
        for(int i = 0; i < nums.size(); i++){
            if(s.contains(-nums[i])) mx = max(mx, abs(nums[i]));
            s.insert(nums[i]);
        }
        return mx;
    }
    // O(n) time, O(n) extra-space, where n is nums.length
};