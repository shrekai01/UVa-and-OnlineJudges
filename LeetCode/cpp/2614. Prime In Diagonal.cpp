class Solution {
public:
    // math
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return n >= 2;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(const int &x : {nums[i][i], nums[i][n - 1 - i]}){
                if(x > ans && isPrime(x)){
                    ans = x;
                }
            }
        }
        return ans;
    }
    // O(n * sqrt(U)) time, O(1) extra-space, where U is max(nums)
};