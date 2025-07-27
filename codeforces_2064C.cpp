#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                
                for (int i = l; i <= r; i++) {
                    long long coins = abs(a[i]);
                    
                    if (a[i] < 0) {
                        if (i > l) coins += dp[l][i-1];
                    } else {
                        if (i < r) coins += dp[i+1][r];
                    }
                    
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }
        
        cout << dp[0][n-1] << "\n";
    }
    
    return 0;
}
