class Solution {
public:
    // greedy
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        if(total_sum % 3 != 0) return false;
        int target = total_sum / 3;
        int now_sum = arr[0];
        int i = 1;
        while(i < n && now_sum != target){
            now_sum += arr[i++];
        }
        if(i >= n) return false;
        now_sum = arr[i++];
        while(i < n && now_sum != target){
            now_sum += arr[i++];
        }
        if(i >= n) return false;
        return true;
    }
    // O(n) time, O(1) extra-space
};