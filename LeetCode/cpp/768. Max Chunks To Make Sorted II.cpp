class Solution {
public:
    // greedy, prefix sum, suffix sum
    // since arr doesn't consist of only [0, n-1] and range(arr[i]) is too large, it is difficult to solve it by property of sums
    // the inequality of equivalent logic in creating a new chunk is
    // max(prefix[0:i]) <= min(suffix[i:n])
    // whenever a index satisfy this inequality, then create a new chunk for it
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> preMax = arr;
        vector<int> sufMin = arr;
        for(int i = 1; i < n; i++){
            preMax[i] = max(preMax[i], preMax[i-1]);
        }

        for(int i = n - 2; i >= 0; i--){
            sufMin[i] = min(sufMin[i], sufMin[i+1]);
        }
        int chunks = 0;
        for(int i = 0; i < n; i++){
            if(i == 0 || preMax[i-1] <= sufMin[i]) chunks++;
        }
        return chunks;
    }
    // O(n) time, O(n) extra-space
};