#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n, ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        int maxm=i*i*i*i-i*i;
        if(i>=4){
            ans=40*(i-4)+48+8*(i-4)*(i-4);
            ans=maxm-ans;
        }
        else{
            if(i==1){
                ans=0;
            }
            if(i==2){
                ans=2*6;
            }
            if(i==3){
                ans=2*28;
            }
        }
        cout<<ans/2<<endl;
}
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
}