class Solution {
public:
    // sliding window
    int minimumRecolors(string blocks, int k) {
        int white_cnt = 0;
        int ans = k;
        for(int i = 0; i < blocks.size(); i++){
            if(blocks[i] == 'W') white_cnt++;
            int left = i - k + 1;
            if(left < 0) continue;

            ans = min(ans, white_cnt);
            
            if(blocks[left] == 'W') white_cnt--;
        }
        return ans;
    }
    // O(n) time, O(1) extra-space, where n is blocks.length
};