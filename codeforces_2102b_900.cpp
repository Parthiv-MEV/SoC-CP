#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    // your code here
    int n;
    cin>>n;
    vector<int> ans;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        ans.push_back(x);
    }
    int a=ans[0];
    int beta=0;
    for(int j=1; j<n; j++){
        if(llabs(a)>llabs(ans[j])) beta++;
    }
    if(beta<=((n/2))) cout<<"YES";
    else cout<<"NO";
    cout<<endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}
