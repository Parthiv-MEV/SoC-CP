#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        
        vector<pair<int,int>> operations;
        
        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1] && a[i] < b[i]){
                operations.push_back({1, i + 1});
                swap(a[i], a[i + 1]);
            }
            if(b[i] > b[i + 1]){
                operations.push_back({2, i + 1});
                swap(b[i], b[i + 1]);
            }
            if(a[i] > b[i]){
                operations.push_back({3, i + 1});
                swap(a[i], b[i]);
            }
        }
        
        cout << operations.size() << "\n";
        for(auto op : operations){
            cout << op.first << " " << op.second << "\n";
        }
    }
    return 0;
}
