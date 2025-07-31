#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, k;
        cin >> a >> b >> k;
        
        long long n = 1, m = 1;
        
        for(long long d = 1; d * d <= k; d++){
            if(k % d == 0){
                long long d1 = d;
                long long d2 = k / d;
                
                if(d1 <= a && d2 <= b){
                    if(d1 < n || (d1 == n && d2 < m)){
                        n = d1;
                        m = d2;
                    }
                }
                
                if(d2 <= a && d1 <= b){
                    if(d2 < n || (d2 == n && d1 < m)){
                        n = d2;
                        m = d1;
                    }
                }
            }
        }
        
        cout << (n % MOD + 7) % MOD << " " << (m % MOD + 7) % MOD << "\n";
    }
    return 0;
}
