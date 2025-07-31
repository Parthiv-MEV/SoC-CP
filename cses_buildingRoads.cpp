#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, adj, visited);
        }
    }
}

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
    
    vector<bool> visited(n + 1, false);
    vector<int> components;
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            components.push_back(i);
            dfs(i, adj, visited);
        }
    }
    
    cout << components.size() - 1 << "\n";
    for(int i = 1; i < components.size(); i++){
        cout << components[0] << " " << components[i] << "\n";
    }
    
    return 0;
}
