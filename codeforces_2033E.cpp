#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        long long total = n * (2 * k + n - 1) / 2;
        long long minDiff = LLONG_MAX;
        
        long long left = 1, right = n;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            
            long long leftSum = mid * (2 * k + mid - 1) / 2;
            long long rightSum = total - leftSum;
            
            long long diff = abs(leftSum - rightSum);
            minDiff = min(minDiff, diff);
            
            if (leftSum < rightSum) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        cout << minDiff << "\n";
    }
    
    return 0;
}
