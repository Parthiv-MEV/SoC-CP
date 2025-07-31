
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        
        long long target_sq = (long long)(qx - px) * (qx - px) + (long long)(qy - py) * (qy - py);
        double target = sqrt(target_sq);
        
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            sum += a;
        }
        
        if(target <= sum && abs(sum - (long long)target) % 2 == 0){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
