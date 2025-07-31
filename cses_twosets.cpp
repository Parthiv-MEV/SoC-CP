#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    int n;
    cin >> n;
    vector<int> vec1={}, vec2={};
    if(n%4==1 || n%4==2) {
        cout<<"NO";
        return;
    }
    else{
        cout<<"YES"<<endl;
    }
    if(n%4==0){
        for(int i=1; i<=n/2; i++){
            if(i%2){
                vec2.push_back(i);
            }
            else{
                vec1.push_back(i);
            }
        }
        for(int i=(n/2)+1;i<=n; i++){
            if(i%2==0){
                vec2.push_back(i);
            }
            else{
                vec1.push_back(i);
            }
        }
    }
    if(n%4==3){
        vec1.push_back(1);
        vec1.push_back(2);
        vec2.push_back(3);
        for(int i=4; i<=n; i++){
            if(i%4==1 || i%4== 2){
                vec1.push_back(i);
            }
            if(i%4==0 || i%4==3 ){
                vec2.push_back(i);
            }
        }
    }
    if(vec1.size())
        cout<<vec1.size()<<endl;
    for(int i=0; i<vec1.size(); i++){
        cout<<vec1[i]<<" ";
    }
    if(vec2.size()) cout<<vec2.size()<<endl;
    cout<<endl;
    for(int i=0; i<vec2.size(); i++){
        cout<<vec2[i]<<" ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}