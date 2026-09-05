#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = (1 << 18) - 1;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x != i) ans &= x;
        }
        cout << ans << endl;
    }
}