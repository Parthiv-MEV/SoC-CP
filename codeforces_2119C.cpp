#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        
        vector<int> a(n, l);
        bool possible = true;
        
        for(int bit = 17; bit >= 0 && possible; bit--){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(a[i] & (1 << bit)) count++;
            }
            
            if(count == n && n % 2 == 0){
                bool found = false;
                for(int i = n-1; i >= 0; i--){
                    int new_val = a[i] ^ (1 << bit);
                    if(new_val >= l && new_val <= r){
                        a[i] = new_val;
                        found = true;
                        break;
                    }
                }
                if(!found) possible = false;
            } else if(count < n && count % 2 == 1){
                bool found = false;
                for(int i = n-1; i >= 0; i--){
                    if(a[i] & (1 << bit)){
                        int new_val = a[i] ^ (1 << bit);
                        if(new_val >= l && new_val <= r){
                            a[i] = new_val;
                            found = true;
                            break;
                        }
                    }
                }
                if(!found) possible = false;
            }
        }
        
        if(!possible){
            cout << -1 << "\n";
        } else {
            for(int i = 0; i < n; i++){
                cout << a[i];
                if(i < n-1) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
