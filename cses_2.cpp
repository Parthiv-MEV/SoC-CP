#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n, x;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        ans.push_back(x);
    }
    if(n==2){
        cout<<3-ans[0];
        return;
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<n-2; i++){
        if(ans[i+1]-ans[i]==2){
            cout<<ans[i]+1;
            return;
        }
    }
    if(ans[0]==2){
        cout<<1;
        return;
    }
    if(ans[n-2]==n-1){
        cout<<n;
        return;
    }


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}