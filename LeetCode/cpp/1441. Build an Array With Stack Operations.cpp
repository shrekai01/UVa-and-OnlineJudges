class Solution {
public:
    // stack
    vector<string> buildArray(vector<int>& target, int n) {
        int num = 1;
        vector<string> ans;
        for(int i = 0; i < target.size(); i++){
            while(num != target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                num++;
            }
            ans.push_back("Push");
            num++;
        }
        return ans;
    }
    // O(mx) time, O(1), where mx is target.back
};