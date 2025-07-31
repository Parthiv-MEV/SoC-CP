#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n, x;
    cin >> n;
    vector<int> vec;

    if(n==1){
        cout<<1;
        return;
    }
    if(n<4){
        cout<<"NO SOLUTION";
        return;
    }
    if(n==4){
        cout<<"2 4 1 3";
        return;
    }

    vec={};
    rep(i,1,n+1){
        if(i%2){
            cout<<i<<" ";
        }
    }
    rep(i,1,n+1){
        if(i%2==0){
            cout<<i<<" ";
        }
    }



}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}