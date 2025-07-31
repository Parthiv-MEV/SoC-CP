#include<bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long mod){
    long long result = 1;
    while(exp > 0){
        if(exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        long long fact = 1;
        for(int i = 1; i <= n + 1; i++){
            fact = (fact * i) % m;
        }
        
        long long sum = 0;
        for(int i = 0; i <= n; i++){
            sum = (sum + power(2, i, m)) % m;
        }
        
        cout << (sum * fact) % m << "\n";
    }
    return 0;
}
