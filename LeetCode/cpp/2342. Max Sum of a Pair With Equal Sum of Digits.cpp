class Solution {
public:
    // single-pass traversal, hash table
    int getDigitSum(int x){
        int sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> ump; // where key at most 9*9(for 999999999)
        int mx = -1;
        for(const int &num : nums){
            int dig_sum = getDigitSum(num);
            if(ump.contains(dig_sum)) mx = max(mx, num + ump[dig_sum]);
            ump[dig_sum] = max(ump[dig_sum], num);
        }
        return mx;
    }
    // O(n * log(U)) time, O(D * log(U)) extra-space, where D = 9 and U = max(nums)
};