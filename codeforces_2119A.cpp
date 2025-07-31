#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, x, y;
        cin >> a >> b >> x >> y;
        
        if(a > b){
            cout << -1 << "\n";
        } else if(a == b){
            cout << 0 << "\n";
        } else {
            cout << (b - a) * min(x, y) << "\n";
        }
    }
    return 0;
}
