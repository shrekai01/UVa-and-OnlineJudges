class Solution {
public:
    // math
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return n >= 2;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while(!isPrime(nums[i])){
            i++;
        }
        while(!isPrime(nums[j])){
            j--;
        }
        return j - i;
    }
    // O(n * sqrt(U)) time, O(1), where U is max(nums) <= 100
};