class Solution {
public:
    // sliding window
    // no matters k is positive or negative, the sliding window always move right.
    // Only the positions of their first window differ
    // The size of window is always |k|
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        int r = (k > 0 ? k + 1 : n); // find the right endpoint of first window
        k = abs(k);
        vector<int> ans(n);
        int sum = std::reduce(code.begin() + r - k, code.begin() + r);
        for(int i = 0; i < n; i++){
            ans[i] = sum;
            sum += code[r % n] - code[(r - k) % n];
            r++;
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is code.length
};