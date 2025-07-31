#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<int> a(n), b(n), c(n), d(n);
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        }
        
        int total_zeros = 0, total_ones = 0;
        int need_zeros = 0, need_ones = 0;
        
        for(int i = 0; i < n; i++){
            total_zeros += a[i];
            total_ones += b[i];
            need_zeros += c[i];
            need_ones += d[i];
        }
        
        if(total_zeros != need_zeros || total_ones != need_ones){
            cout << -1 << "\n";
            continue;
        }
        
        int operations = 0;
        for(int i = 0; i < n; i++){
            operations += abs(a[i] - c[i]);
        }
        
        cout << operations / 2 << "\n";
    }
    return 0;
}
