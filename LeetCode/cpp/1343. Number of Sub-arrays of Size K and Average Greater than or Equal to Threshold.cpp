class Solution {
public:
    // sliding window
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            int left = i - k + 1;
            if(left < 0) continue;
            
            if(sum >= threshold) ans++;

            sum -= arr[left];
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is arr.length
};