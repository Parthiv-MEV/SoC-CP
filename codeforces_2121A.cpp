#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        if(n == 0){
            cout << 0 << "\n";
            continue;
        }
        
        int minPos = *min_element(a.begin(), a.end());
        int maxPos = *max_element(a.begin(), a.end());
        
        int dist1 = abs(s - minPos) + abs(maxPos - minPos);
        int dist2 = abs(s - maxPos) + abs(maxPos - minPos);
        
        cout << min(dist1, dist2) << "\n";
    }
    return 0;
}
