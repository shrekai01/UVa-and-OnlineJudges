#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long ll;

// constructive algorithms, greedy, math, sorting

// place the max element at index 0, and then place distinct elements in increasing order at index [1, n)
// Lastly place the duplicate elements(if any) at the rightmost. This achieves optimal answer.
int main(){
    int t; cin >> t;
    unordered_map<int, int> m;
    while(t--){
        m.clear();
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        swap(a[0], a[n - 1]);
        sort(a.begin() + 1, a.end());
        int mex = 0, mx = 0;
        ll ans = 0;
        vector<int> v1, v2;
        for(int i = 1; i < n; i++){
            if(v1.size() && v1.back() == a[i]) v2.push_back(a[i]);
            else v1.push_back(a[i]);
        }
        int idx = 1;
        for(int i = 0; i < v1.size(); i++) a[idx++] = v1[i];
        for(int i = 0; i < v2.size(); i++) a[idx++] = v2[i];
        
        for(int i = 0; i < n; i++){
            m[a[i]]++;
            mx = max(mx, a[i]);
            while(m[mex]) mex++;
            ans += mex + mx;
        }

        cout << ans << endl;
    }
    // O(N * log(N)) time, O(n) extra-space, where N is the sum of n over all test cases(which does not exceed 2 * 10^5)
}