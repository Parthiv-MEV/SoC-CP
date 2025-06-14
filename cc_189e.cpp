#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

#include <algorithm>
#include <utility> // for std::pair



int memoize(int i, vector<int>& memo, vector<vector <int>> map, vector<int> ans, int max){
    if(memo[i]==-1){
        return memo[i];
    }
    if(ans[i]==max){
        memo[i]==0;
        return 0;
    }
    else{
        int z=ans[i]+1;
        vector<int> locns=map[z];
        sort(locns.begin(), locns.end());
        int p=locns.size();
        int min=abs(i-locns[0])+memoize(locns[0]);
        for (int j=0;j<locns.size();j++){
            k=locns[j];
            val=abs(i-k)+memoize(k);
            if(val < min){
                min=val;
            }
        }
        memo[i]=min;
        return min;
        
    }
}

void solve() {
    int n, x, max;
    cin >> n>>max;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans.push_back(x);
    }
    vector<vector <int>> map(max+1,-1);
    vector<int> memo(n+1, 0LL);

    for(int i=0; i<n;i++){
        map[ans[i]].push_back(i);
    }
    for(int i=0; i<n; i++){
        cout<<memoize(i, memo, map, ans)<<' ';
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