#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> grid(2);
        cin >> grid[0] >> grid[1];
        
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        bool canReach = false;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == 1 && c == n - 1) {
                canReach = true;
                break;
            }
            
            if (grid[r][c] == '>') {
                if (c + 1 < n && !visited[r][c + 1]) {
                    visited[r][c + 1] = true;
                    q.push({r, c + 1});
                }
            } else {
                if (c - 1 >= 0 && !visited[r][c - 1]) {
                    visited[r][c - 1] = true;
                    q.push({r, c - 1});
                }
            }
            
            if (!visited[1 - r][c]) {
                visited[1 - r][c] = true;
                q.push({1 - r, c});
            }
        }
        
        cout << (canReach ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
