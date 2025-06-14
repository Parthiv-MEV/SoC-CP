#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n, x, c;
    cin >> n;
    cin >> c;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.push_back(x);
    }

    int max_val = *max_element(a.begin(), a.end());
    vector<bool> boolean(max_val + 1, false);
    vector<int> mins(max_val + 1, -1);

    for(int i=0;i<n;i++){
        int y=a[i];
        int z=b[i];
        if(boolean[y]==false){
            boolean[y]=true;
            mins[y]=z;
        }
        if(boolean[y]){
            if(mins[y]>z){
                mins[y]=z;
            }
        }
    }
    int sum=0;
    int count=0;
    for(int i=0; i<max_val; i++){
        if(boolean[i] && mins[i]<c){
            sum+=mins[i];
            count++;
        }
    }
    cout<<c*count-sum<<endl;



}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}