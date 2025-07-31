#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, k;
        cin >> a >> b >> k;
        
        long long cost = 0;
        set<pair<long long, long long>> used;
        
        while(a > 0 || b > 0){
            long long dx = min(a, k);
            long long dy = min(b, k);
            
            if(used.count({dx, dy})){
                cost += 0;
            } else {
                cost += 1;
                used.insert({dx, dy});
            }
            
            a -= dx;
            b -= dy;
        }
        
        cout << cost << "\n";
    }
    return 0;
}
