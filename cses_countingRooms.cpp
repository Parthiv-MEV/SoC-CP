#include<bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<string>& grid, int n, int m){
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#'){
        return;
    }
    
    grid[x][y] = '#';
    
    dfs(x + 1, y, grid, n, m);
    dfs(x - 1, y, grid, n, m);
    dfs(x, y + 1, grid, n, m);
    dfs(x, y - 1, grid, n, m);
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    
    int rooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                rooms++;
                dfs(i, j, grid, n, m);
            }
        }
    }
    
    cout << rooms << "\n";
    return 0;
}
