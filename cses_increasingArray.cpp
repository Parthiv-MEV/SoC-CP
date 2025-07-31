#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n, x;
    cin >> n;
    if(n==0|| n==1){
        cout<<0;
        return;
    }
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }

    int ans=0;
    for(int i=1; i<n; i++){
        if(vec[i]<vec[i-1]){
            ans+=vec[i-1]-vec[i];
            vec[i]=vec[i-1];
        }
    }
    cout<< ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

}