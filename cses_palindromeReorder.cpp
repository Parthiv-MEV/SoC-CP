#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

void solve() {
    string str;
    cin >> str;
    vector <char> vec;
    int count[26]={};
    int odd=0;
    for(int i=0; i<str.length(); i++){
        char c=str[i];
        int p=c-'A';
        count[p]++;
    }
    for(int i=0; i<26; i++){
        if(odd!=0 && count[i]%2==1){
            cout<<"NO SOLUTION";
            return;
        }
        else if(count[i]%2==1){
            odd=i+1;
        }
    }
    for(int i=0; i<26; i++){
        if(odd==i+1) continue;
        for(int j=0; j<(count[i]/2); j++){
            char x='A'+i;
            cout<<x;
            vec.insert(vec.begin(),x);
        }

    }
    for(int i=0;odd && i<count[odd-1]; i++){
        char x='A'+odd-1;
        cout<<x;
    }
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // uncomment if multiple test cases
    while (t--) solve();
}