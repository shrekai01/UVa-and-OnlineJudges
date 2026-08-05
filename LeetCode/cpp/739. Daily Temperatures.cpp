class Solution {
public:
    // monotonic stack
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> st; // store indices of temperatures
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
    // O(n) time, O(min(n, U)) extra-space, where U is max(temperatures) - min(temperatures) + 1(71)
};