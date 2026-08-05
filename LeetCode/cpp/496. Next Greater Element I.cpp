class Solution {
public:
    // monotonic stack
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> idx;
        stack<int> st;
        for(int i = 0; i < n; i++){
            idx[nums1[i]] = i;
        }
        for(int i = m - 1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(idx.contains(nums2[i])){
                if(!st.empty()){
                    nums1[idx[nums2[i]]] = st.top();
                }
                else{
                    nums1[idx[nums2[i]]] = -1;
                }
            }
            st.push(nums2[i]);
        }
        return nums1;
    }
    // O(n + m) = O(m) time, O(n + m) = O(m) extra-space
};