#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin>>a>>b;
    float m=0.5;
    float g=3/8;
    float ans=(a+1)*m+(b)*g;
    float roundedUp = std::ceil(ans);

    cout<<roundedUp;
}