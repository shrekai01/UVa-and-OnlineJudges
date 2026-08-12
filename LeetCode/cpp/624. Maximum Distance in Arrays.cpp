class Solution {
public:
    // single-pass traversal
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = (int)1e4 + 1, mx = (int)-1e4 - 1;
        int ans = 0;
        for(const vector<int> &arr : arrays){
            ans = max({ans, arr.back() - mn, mx - arr[0]});
            mn = min(mn, arr[0]);
            mx = max(mx, arr.back());
        }
        return ans;
    }
    // O(m) time, O(1) extra-space
};