class StockSpanner {
public:
    // monotonic stack
    stack<pair<int, int>> st;
    StockSpanner() {
        st = stack<pair<int, int>>();
    }
    
    int next(int price) {
        int cnt = 1;
        while(!st.empty() && st.top().first <= price){
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
    // O(n) time, O(min(n, U)) extra-space, where n is the number of calls to next and U is the range of price
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */