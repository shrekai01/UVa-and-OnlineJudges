class Solution {
public:
    // greedy, prefix sum
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int sortedPrefixSum = 0;
        int prefixSum = 0;
        for(int i = 0; i < n; i++){
            prefixSum += arr[i];
            sortedPrefixSum += i;
            if(prefixSum == sortedPrefixSum) ans++; // by the property of sums
        }
        return ans;
    }
    // O(n) time, O(1) extra-space
};