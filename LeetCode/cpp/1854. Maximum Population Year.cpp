class Solution {
public:
    // difference array
    static constexpr int offset = 1950;
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int> diff(101);
        for(int i = 0; i < n; i++){
            diff[logs[i][0] - offset]++;
            diff[logs[i][1] - offset]--;
        }
        int mx = 0, mx_year = 0, s = 0;
        for(int i = 0; i < 101; i++){
            s += diff[i];
            if(s > mx){
                mx = s;
                mx_year = i;
            }
        }
        return mx_year + offset;
    }
    // O(n + U) time, O(U) extra-space, where n is logs.length and U is max(death) - min(birth) + 1
};