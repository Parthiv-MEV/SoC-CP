#include<bits/stdc++.h>
using namespace std;

bool isGood(long long n){
    for(long long i = 2; i * i <= n; i++){
        if(n % i == 0){
            if(i < 10) return false;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1 && n < 10) return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long l, r;
        cin >> l >> r;
        
        long long count = 0;
        for(long long i = l; i <= r; i++){
            if(isGood(i)) count++;
        }
        
        cout << count << "\n";
    }
    return 0;
}
