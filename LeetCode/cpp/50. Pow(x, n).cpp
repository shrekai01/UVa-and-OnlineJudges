class Solution {
public:
    // exponentiating by squaring
    double qpow(double x, int N){
        double res = 1;
        long long n = N; // converting 2^(-31) to 2^31 may overflow
        if(n < 0){
            n = -n;
            x = 1 / x;
        }
        while(n){
            if(n & 1){
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
    double myPow(double x, int n) {
        return qpow(x, n);
    }
    // O(log|n|) time, O(1) extra-space
};