#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n, x;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans.push_back(x);
    }

    int distinct=0;
    int a=-1, b=-1;
    bool ataken=false, btaken=false;
    for(auto y:x){
        if (!ataken){
            ataken=true;
            a=y;
        }
        else if (!btaken){
            btaken=true;
            b=y;
        }
        else{
            break;
        }
    if (ataken && btaken){
            return 2;
        }
    else{
        return -1
    }
    }


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    while (t--) cout<<solve();
}