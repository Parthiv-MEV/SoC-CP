#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> color(n + 1, -1);
    bool possible = true;
    
    for(int i = 1; i <= n && possible; i++){
        if(color[i] == -1){
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while(!q.empty() && possible){
                int u = q.front();
                q.pop();
                
                for(int v : adj[u]){
                    if(color[v] == -1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if(color[v] == color[u]){
                        possible = false;
                        break;
                    }
                }
            }
        }
    }
    
    if(!possible){
        cout << "IMPOSSIBLE\n";
    } else {
        for(int i = 1; i <= n; i++){
            cout << color[i] + 1;
            if(i < n) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
