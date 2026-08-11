#include <iostream>
#include <string>

using namespace std;

// constructive algorithms, greedy

// cond 1: if a string is a candidate of being a regular bracket sequences, then its number of ( must be as same with its number of )
// cond 2: Moreover, for each prefix, the number of ) must not exceed the number of (

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string a, b; cin >> a >> b;
        string s1 = "", s2 = "";
        int f = 1;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]) s1 += a[i], s2 += b[i]; // have no choice
            else{ // greedy part, if a[i] != b[i], we choose alternatively in the following order.
                if(f == 1) s1 += "(", s2 += ")";
                else s1 += ")", s2 += "(";
                f = (f == 1 ? 0 : 1);
            }
        }
        
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] == '(') cnt1++;
            else cnt1--;
            
            if(s2[i] == '(') cnt2++;
            else cnt2--;

            if(cnt1 < 0 || cnt2 < 0) f = 0; // for cond 2
        }
        if(cnt1 != 0 || cnt2 != 0) f = 0; // for cond 1
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}