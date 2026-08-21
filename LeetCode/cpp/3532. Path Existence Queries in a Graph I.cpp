class Solution {
public:
    // Union-Find
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> grp_id(n);
        for(int i = 1; i < n; i++){
            grp_id[i] = grp_id[i - 1] + (abs(nums[i] - nums[i - 1]) > maxDiff);
        }
        
        vector<bool> res;
        for(vector<int> &q : queries){
            if(grp_id[q[0]] == grp_id[q[1]]) res.emplace_back(true);
            else res.emplace_back(false);
        }
        return res;
    }
    // O(n + q) time, O(n) extra-space, where q is queries.length
};