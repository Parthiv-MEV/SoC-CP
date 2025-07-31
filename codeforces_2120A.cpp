#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<pair<int,int>> rects(3);
        for(int i = 0; i < 3; i++){
            cin >> rects[i].first >> rects[i].second;
        }
        
        long long total_area = 0;
        for(auto& rect : rects){
            total_area += (long long)rect.first * rect.second;
        }
        
        long long side = sqrt(total_area);
        if(side * side != total_area){
            cout << "NO\n";
            continue;
        }
        
        bool possible = false;
        for(int mask = 0; mask < 8; mask++){
            vector<pair<int,int>> r(3);
            for(int i = 0; i < 3; i++){
                if(mask & (1 << i)){
                    r[i] = {rects[i].second, rects[i].first};
                } else {
                    r[i] = rects[i];
                }
            }
            
            sort(r.begin(), r.end());
            do {
                if(r[0].first == r[1].first && r[0].first + r[2].first == side && 
                   r[0].second + r[1].second == side && r[2].second == side){
                    possible = true;
                }
                if(r[0].second == r[1].second && r[0].second + r[2].second == side && 
                   r[0].first + r[1].first == side && r[2].first == side){
                    possible = true;
                }
            } while(next_permutation(r.begin(), r.end()));
        }
        
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}
