class Solution {
public:
    // monotonic stack
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res = prices;
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && prices[i] < st.top()){
                st.pop();
            }
            if(!st.empty()){
                res[i] -= st.top();
            }
            st.push(prices[i]);
        }
        return res;
    }
    // O(n) time, O(n) extra-space since stack can have duplicate values
};