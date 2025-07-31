#include <bits/stdc++.h>
using namespace std

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n;
    cin >> n;
    int ans=1;
    for(int i=0; i<n; i++){
        ans*=2;
        ans%=1000000007;
    }
    cout<<ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}