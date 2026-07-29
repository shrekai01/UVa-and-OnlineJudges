class Solution {
public:
    // brute force
    string removeDigit(string number, char digit) {
        int n = number.size();
        string res = "0";
        for(int i = 0; i < n; i++){
            if(number[i] == digit){
                string now_s = number.substr(0, i) + number.substr(i + 1, n);
                if(now_s > res){
                    res = now_s;
                }
            }
        }
        return res;
    }
    // O(n^2) time, O(n) extra-space
};