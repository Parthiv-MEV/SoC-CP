#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        
        int minMax = INT_MAX;
        
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                vector<vector<int>> temp = a;
                
                for(int i = 0; i < n; i++){
                    temp[i][c]--;
                }
                for(int j = 0; j < m; j++){
                    temp[r][j]--;
                }
                temp[r][c]++;
                
                int maxVal = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        maxVal = max(maxVal, temp[i][j]);
                    }
                }
                
                minMax = min(minMax, maxVal);
            }
        }
        
        cout << minMax << "\n";
    }
    return 0;
}
