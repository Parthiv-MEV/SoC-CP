#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long power(long long a, long long b, long long mod){
    long long res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

long long modInverse(long long a, long long mod){
    return power(a, mod - 2, mod);
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<long long> prob(m + 1, 1);
    
    for(int i = 0; i < n; i++){
        long long l, r, p, q;
        cin >> l >> r >> p >> q;
        
        long long inv_q = modInverse(q, MOD);
        long long segment_prob = (p * inv_q) % MOD;
        long long not_prob = (1 - segment_prob + MOD) % MOD;
        
        for(long long j = l; j <= r; j++){
            prob[j] = (prob[j] * not_prob) % MOD;
        }
    }
    
    long long result = 1;
    for(int i = 1; i <= m; i++){
        result = (result * prob[i]) % MOD;
    }
    
    cout << result << "\n";
    return 0;
}
