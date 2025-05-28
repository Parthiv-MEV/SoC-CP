#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n, x, k;
    cin >> n;
    cin>> k;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans.push_back(x);
    }

    int alpha=(n-k-1)/2;
    int beta=n-1-alpha;
    int prev=-1;
    int count=0;
    sort(ans.begin(), ans.end());
    for(int i=ans[alpha]; i<ans[beta]+1; i++){
        count++;
    }

    cout<<count<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}