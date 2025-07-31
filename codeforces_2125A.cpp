#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        bool hasFTT = s.find("FTT") != string::npos;
        bool hasNTT = s.find("NTT") != string::npos;
        
        if(!hasFTT && !hasNTT){
            cout << s << "\n";
            continue;
        }
        
        sort(s.begin(), s.end());
        
        do {
            if(s.find("FTT") == string::npos && s.find("NTT") == string::npos){
                cout << s << "\n";
                break;
            }
        } while(next_permutation(s.begin(), s.end()));
    }
    return 0;
}
