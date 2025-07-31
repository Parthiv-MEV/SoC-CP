#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        bool found = false;
        
        for(int i = 1; i < n && !found; i++){
            for(int j = i + 1; j < n && !found; j++){
                string a = s.substr(0, i);
                string b = s.substr(i, j - i);
                string c = s.substr(j);
                
                if(a.find(b) != string::npos && c.find(b) != string::npos){
                    found = true;
                }
            }
        }
        
        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}
