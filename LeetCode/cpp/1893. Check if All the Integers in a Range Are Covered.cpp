class Solution {
public:
    // difference array
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();
        int max_end = ranges::max(ranges, {}, [](const auto &a){return a[1];})[1];
        vector<int> diff(max_end + 2);
        for(int i = 0; i < n; i++){
            diff[ranges[i][0]]++;
            diff[ranges[i][1] + 1]--;
        }
        for(int i = 1; i <= max_end; i++){
            diff[i] += diff[i - 1];
        }
        
        for(int i = left; i <= right; i++){
            if(i > max_end) return false;
            if(diff[i] <= 0) return false;
        }
        return true;
    }
    // O(n + U + L) time, O(U) extra-space, where n is ranges.length, U is max_end and L is right - left + 1
};