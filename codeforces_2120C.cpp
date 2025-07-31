#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        if(m < n || m > (long long)n * (n + 1) / 2){
            cout << -1 << "\n";
            for(int i = 0; i < n - 1; i++){
                cout << "1 1\n";
            }
            continue;
        }
        
        vector<int> parent(n + 1);
        parent[1] = 0;
        
        int remaining = m - n;
        int current = 2;
        
        for(int depth = 2; depth <= n && remaining > 0; depth++){
            int nodes_at_depth = min(remaining / (depth - 1), n - current + 1);
            for(int i = 0; i < nodes_at_depth && current <= n; i++){
                parent[current] = 1;
                remaining -= (depth - 1);
                current++;
            }
            if(current <= n && remaining > 0){
                parent[current] = current - 1;
                current++;
            }
        }
        
        while(current <= n){
            parent[current] = current - 1;
            current++;
        }
        
        cout << 1 << "\n";
        for(int i = 2; i <= n; i++){
            cout << parent[i] << " " << i << "\n";
        }
    }
    return 0;
}
