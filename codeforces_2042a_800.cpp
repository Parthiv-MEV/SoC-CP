#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n, x, k, sum=0;
    cin >> n;
    cin>>k;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans.push_back(x);
        sum+=x;
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    int tempsum=0;
    for(int i=0; i<n; i++){
        tempsum+=ans[i];
        if(tempsum==k){
            cout<<0<<endl;
            return;
        }
        if(tempsum>k){
            tempsum-=ans[i];
            break;
        }
        }
        cout<<k-tempsum<<endl;
        return;
    }


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}