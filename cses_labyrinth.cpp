#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    
    int startR = -1, startC = -1, endR = -1, endC = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                startR = i;
                startC = j;
            }
            if(grid[i][j] == 'B'){
                endR = i;
                endC = j;
            }
        }
    }
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<char>> parent(n, vector<char>(m));
    queue<pair<int, int>> q;
    
    q.push({startR, startC});
    dist[startR][startC] = 0;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
               grid[nx][ny] != '#' && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = dir[i];
                q.push({nx, ny});
            }
        }
    }
    
    if(dist[endR][endC] == -1){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << dist[endR][endC] << "\n";
        
        string path = "";
        int x = endR, y = endC;
        
        while(x != startR || y != startC){
            char c = parent[x][y];
            path += c;
            if(c == 'U') x++;
            else if(c == 'D') x--;
            else if(c == 'L') y++;
            else if(c == 'R') y--;
        }
        
        reverse(path.begin(), path.end());
        cout << path << "\n";
    }
    
    return 0;
}
