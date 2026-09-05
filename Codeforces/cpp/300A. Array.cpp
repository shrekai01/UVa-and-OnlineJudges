#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    vector<vector<int>> set(3);
    int p = 1;
    int neg_cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 0) neg_cnt++;
    }
    bool placed = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            set[2].push_back(arr[i]);
        }
        else if(arr[i] < 0){
            if(set[0].size() == 0){
                set[0].push_back(arr[i]);
                neg_cnt--;
            }
            else{
                if(neg_cnt % 2 == 1 && !placed){
                    placed = true;
                    set[2].push_back(arr[i]);
                }
                else{
                    set[1].push_back(arr[i]);
                }
            }
        }
        else{
            set[1].push_back(arr[i]);
        }
    }
    for(int k = 0; k < 3; k++){
        cout << set[k].size();
        for(int i = 0; i < set[k].size(); i++){
            cout << " " << set[k][i];
        }
        cout << endl;
    }
}