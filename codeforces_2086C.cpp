#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long sum = 0;
        long long maxSum = LLONG_MIN;
        
        for (int i = 0; i < n; i++) {
            sum += a[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += a[i];
        }
        
        if (maxSum <= 0) {
            cout << total << "\n";
        } else {
            long long result = total;
            long long temp = maxSum;
            for (int i = 0; i < k; i++) {
                result += temp;
                temp *= 2;
            }
            cout << result << "\n";
        }
    }
    
    return 0;
}
