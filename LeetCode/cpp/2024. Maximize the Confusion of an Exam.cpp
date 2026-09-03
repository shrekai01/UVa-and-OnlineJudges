class Solution {
public:
    // sliding window
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        int cnt[2]{};
        int left = 0;
        for(int i = 0; i < answerKey.size(); i++){
            cnt[(answerKey[i] >> 1) & 1]++;
            while(cnt[0] > k && cnt[1] > k){
                cnt[(answerKey[left] >> 1) & 1]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is answerKey.length
};