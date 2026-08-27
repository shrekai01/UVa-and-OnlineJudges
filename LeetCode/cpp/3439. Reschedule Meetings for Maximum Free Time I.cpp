class Solution {
public:
    // sliding window, greedy
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int time = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            time += endTime[i] - startTime[i];
            int left = i - k + 1;
            if(left < 0) continue;
            ans = max(ans, (i == n - 1 ? eventTime : startTime[i + 1]) - ((left == 0 ? 0 : endTime[left - 1]) + time));
            time -= endTime[left] - startTime[left];
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is startTime.length == endTime.length
};