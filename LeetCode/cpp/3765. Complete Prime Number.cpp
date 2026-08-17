class Solution {
public:
    // math
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return n >= 2;
    }
    bool completePrime(int num) {
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++){
            int pre = stoi(s.substr(0, i + 1));
            if(!isPrime(pre)) return false;
            int suf = stoi(s.substr(i));
            if(!isPrime(suf)) return false;
        }
        return true;
    }
    // O(sqrt(num)) time, O(log(num)) extra-space
    // since sqrt(n) * (1 + 1/10^(1/2) + 1 /10^(1/3) + ...) < sqrt(n) * 2
};