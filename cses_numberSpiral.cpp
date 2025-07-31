#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int x, y,;
    cin >> y >>x;
    int maxm=max(x,y);
    int corner=(maxm-1)*(maxm-1)+maxm;
    if(maxm%2==0) ans=corner+y-x;
    else ans=corner+x-y;
    cout<<ans<<" ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}