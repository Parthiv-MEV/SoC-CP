#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        
        int count = 0;
        for(int i = 0; i < n; i++){
            int dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            
            set<tuple<int,int,int,int>> visited;
            
            while(true){
                if(visited.count({x, y, dx, dy})){
                    break;
                }
                visited.insert({x, y, dx, dy});
                
                if((x == 0 || x == s) && (y == 0 || y == s)){
                    count++;
                    break;
                }
                
                int nx = x + dx;
                int ny = y + dy;
                
                if(nx <= 0){
                    nx = -nx;
                    dx = -dx;
                }
                if(nx >= s){
                    nx = 2*s - nx;
                    dx = -dx;
                }
                if(ny <= 0){
                    ny = -ny;
                    dy = -dy;
                }
                if(ny >= s){
                    ny = 2*s - ny;
                    dy = -dy;
                }
                
                x = nx;
                y = ny;
            }
        }
        
        cout << count << "\n";
    }
    return 0;
}
