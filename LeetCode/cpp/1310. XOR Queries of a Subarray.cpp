class Solution {
public:
    // prefix sum
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        vector<int> pre_sum(n + 1);
        for(int i = 0; i < n; i++){
            pre_sum[i + 1] = pre_sum[i] ^ arr[i];
        }
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            const auto &q = queries[i];
            ans[i] = pre_sum[q[1] + 1] ^ pre_sum[q[0]];
        }
        return ans;
    }
    // O(n + m) time, O(n) extra-space, where n is arr.length, m is queries.length
};