class Solution {
public:
    // sliding window
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0, sum = 0;
        for(int i = n - k; i < n + k; i++){
            sum += cardPoints[i % n];
            int left = i - k + 1;
            if(left < n - k) continue;
            
            ans = max(ans, sum);
            
            sum -= cardPoints[left % n];
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is cardPoints.length
};