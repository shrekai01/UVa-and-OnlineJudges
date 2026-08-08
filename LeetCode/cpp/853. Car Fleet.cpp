class Solution {
public:
    // monotonic stack
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++){
            vec[i] = {position[i], speed[i]};
        }
        sort(vec.begin(), vec.end(), [](auto a, auto b) -> bool{return a.first < b.first;});
        vector<double> times(n);
        for(int i = 0; i < n; i++){
            auto &[p, s] = vec[i];
            times[i] = double(target - p) / s;
        }
        stack<double> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && times[i] >= st.top()){
                st.pop();
            }
            st.push(times[i]);
        }
        return st.size();
    }
    // O(n*log(n)) time, O(min(n, U)) extra-space, where n is position.length and U is range of (target - position[i]) / speed[i]
};