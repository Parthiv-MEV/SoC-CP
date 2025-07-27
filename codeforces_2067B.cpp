#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> count_a_vec(n + 1, 0);
    int max_val_in_a = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        count_a_vec[val]++;
        if (val > max_val_in_a) {
            max_val_in_a = val;
        }
    }

    int v_max = max_val_in_a + n / 2 + 1;
    std::vector<long long> c_a(v_max + 1, 0);
    for (int i = 1; i <= v_max; ++i) {
        c_a[i] = c_a[i - 1];
        if (i < count_a_vec.size()) {
            c_a[i] += count_a_vec[i];
        }
    }

    std::vector<bool> dp(n / 2 + 1, false);
    std::vector<bool> dp_nonzero(n / 2 + 1, false);

    dp[0] = true;

    for (int v = 1; v <= v_max; ++v) {
        std::vector<bool> new_dp(n / 2 + 1, false);
        std::vector<bool> new_dp_nonzero(n / 2 + 1, false);

        std::vector<bool> has_dp(n / 2 + 1, false);
        std::vector<bool> has_dp_nonzero(n / 2 + 1, false);

        has_dp[0] = dp[0];
        has_dp_nonzero[0] = dp_nonzero[0];
        for (int i = 1; i <= n / 2; ++i) {
            has_dp[i] = dp[i] || has_dp[i - 1];
            has_dp_nonzero[i] = dp_nonzero[i] || has_dp_nonzero[i - 1];
        }

        long long limit = (c_a[v - 1] > 0) ? (c_a[v - 1] - 1) / 2 : -1;

        for (int k = 0; k <= n / 2; ++k) {
            if (c_a[v] < 2LL * k) {
                continue;
            }
            
            bool possible = false;
            if (limit >= 0 && k >= 0) {
                if (has_dp_nonzero[std::min(k, (int)limit)]) {
                    possible = true;
                }
            }
            if (!possible && k > limit) {
                bool val_at_limit = (limit >= 0) ? has_dp[limit] : false;
                if (has_dp[k] != val_at_limit) {
                    possible = true;
                }
            }
            if (possible) {
                new_dp[k] = true;
            }
        }

        for (int k = 1; k <= n / 2; ++k) {
            if (!new_dp[k]) continue;

            bool possible_nonzero = false;
            int upper_k = k - 1;
            if (limit >= 0 && upper_k >= 0) {
                if (has_dp_nonzero[std::min(upper_k, (int)limit)]) {
                    possible_nonzero = true;
                }
            }
            if (!possible_nonzero && upper_k > limit) {
                bool val_at_limit = (limit >= 0) ? has_dp[limit] : false;
                if (has_dp[upper_k] != val_at_limit) {
                    possible_nonzero = true;
                }
            }
            if (possible_nonzero) {
                new_dp_nonzero[k] = true;
            }
        }
        
        dp = new_dp;
        dp_nonzero = new_dp_nonzero;
        if(dp[n/2]) break;
    }

    if (dp[n / 2]) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
