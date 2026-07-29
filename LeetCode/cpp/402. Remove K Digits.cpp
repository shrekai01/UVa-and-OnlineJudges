class Solution {
public:
    // greedy
    // monotonic stack
    // keep the stack sorted increasingly from bottom to top
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        if(k == 0) return num;
        stack<char> s;
        s.push(num[0]);
        for(int i = 1; i < n; i++){
            while(k && !s.empty() && num[i] < s.top()){
                k--;
                s.pop();
            }
            s.push(num[i]);
            if(s.size() == 1 && s.top() == '0'){
                s.pop();
            }
        }
        while(k && !s.empty()){
            k--;
            s.pop();
        }
        // take the elements out of the stack and reverse it back to original order
        string res = "";
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        if(res.size() == 0) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
    // O(n) time, O(n) extra-space
};