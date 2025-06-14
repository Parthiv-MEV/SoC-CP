#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

int f(int x, int a, int b, int c, int d, int n){
    c=max(c, d);
    return a*x+b*(n-x)+c*x*(n-x);
}
void solve() {
    int n, a, b, c, d;
    cin >>n>>a>>b>>c>>d;
    if(c==0 && d==0){
        cout<<n*max(a,b)<<endl;
        return;
    }
    c=max(c,d);
    int temp = (int)round((double)(c*n + a - b) / (2 * c));
    int alpha = max(0LL, min(temp, n));
    cout<<f(alpha,a,b,c,d,n)<<endl;
    
}



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}