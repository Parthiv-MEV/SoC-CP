#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int x, y;
    cin>>x>>y;
    bool ans=false;
        if((x+y)%3==0 && x<=y*2 && 2*x>=y){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }

    cout<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}