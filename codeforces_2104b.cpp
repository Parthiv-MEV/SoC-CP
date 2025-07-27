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
        vector<long long> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<long long> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + a[i];
        }
        
        vector<long long> max_prefix(n);
        max_prefix[0] = a[0];
        for (int i = 1; i < n; i++) {
            max_prefix[i] = max(max_prefix[i - 1], a[i]);
        }
        
        for (int k = 1; k <= n; k++) {
            long long result = suffix[n - k];
            if (k < n) {
                result = max(result, suffix[n - k + 1] + max_prefix[n - k - 1]);
            }
            cout << result;
            if (k < n) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
