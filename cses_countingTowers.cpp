#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int t;
    cin >> t;
    
    vector<long long> dp1(1000001), dp2(1000001);
    dp1[1] = dp2[1] = 1;
    
    for(int i = 2; i <= 1000000; i++){
        dp1[i] = (4 * dp1[i-1] + dp2[i-1]) % MOD;
        dp2[i] = (dp1[i-1] + 2 * dp2[i-1]) % MOD;
    }
    
    while(t--){
        int n;
        cin >> n;
        cout << (dp1[n] + dp2[n]) % MOD << "\n";
    }
    return 0;
}
