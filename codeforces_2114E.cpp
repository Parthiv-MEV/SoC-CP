#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<long long> a;
vector<long long> dp1;
vector<long long> dp2;

void dfs(int u, int p) {
    long long parent_dp1_max = 0;
    long long parent_dp2_max = 0;

    if (p != -1) {
        parent_dp1_max = max(0LL, dp1[p]);
        parent_dp2_max = max(0LL, dp2[p]);
    }

    dp1[u] = a[u] + parent_dp2_max;
    dp2[u] = -a[u] + parent_dp1_max;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n, vector<int>());
    a.assign(n, 0);
    dp1.assign(n, 0);
    dp2.assign(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    for (int i = 0; i < n; ++i) {
        cout << dp1[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
