#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<pair<pair<long long, long long>, int>> points(n);
        for(int i = 0; i < n; i++){
            long long x, y;
            cin >> x >> y;
            points[i] = {{x + y, x - y}, i + 1};
        }
        
        sort(points.begin(), points.end());
        
        for(int i = 0; i < n; i += 2){
            cout << points[i].second << " " << points[i + 1].second << "\n";
        }
    }
    return 0;
}
