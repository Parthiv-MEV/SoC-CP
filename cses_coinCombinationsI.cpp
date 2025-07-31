#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= x; i++){
        for(int coin : coins){
            if(i >= coin){
                dp[i] = (dp[i] + dp[i - coin]) % MOD;
            }
        }
    }
    
    cout << dp[x] << "\n";
    return 0;
}
