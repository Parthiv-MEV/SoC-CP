#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve(int t) {
    cout<<t<<" ";
    if(t==1){
        return;
    }
    if (t%2) {
        solve(3*t+1);
    }
    else if( t%2==0){
        solve(t/2);
    }
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    solve(t);
}