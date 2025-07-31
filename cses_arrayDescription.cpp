#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    
    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));
    
    if(x[0] == 0){
        for(int j = 1; j <= m; j++){
            dp[0][j] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }
    
    for(int i = 1; i < n; i++){
        if(x[i] == 0){
            for(int j = 1; j <= m; j++){
                for(int k = max(1, j-1); k <= min(m, j+1); k++){
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                }
            }
        } else {
            for(int k = max(1, x[i]-1); k <= min(m, x[i]+1); k++){
                dp[i][x[i]] = (dp[i][x[i]] + dp[i-1][k]) % MOD;
            }
        }
    }
    
    long long result = 0;
    for(int j = 1; j <= m; j++){
        result = (result + dp[n-1][j]) % MOD;
    }
    
    cout << result << "\n";
    return 0;
}
