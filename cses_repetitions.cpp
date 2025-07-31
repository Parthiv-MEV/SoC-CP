#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; ++i)


int reps(string a){
    char curr='1';
    int count=0;
    int max_count=0;
    for(int i=0;i<a.length();i++){
        if(a[i]==curr){
            count++;
        }
        else{
            count=1;
            curr=a[i];
        }
        if(max_count<count){
                max_count=count;
        }
    }
    return max_count;
}

int32_t main(){
    string pakodi;
    cin>>pakodi;
    cout<<reps(pakodi);
    return 0;
}