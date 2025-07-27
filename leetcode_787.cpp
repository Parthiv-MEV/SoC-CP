#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for (auto& e : flights) g[e[0]].emplace_back(e[1], e[2]);
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<>> q;
        dist[src][k+1]=0;
        q.emplace(0, src, k+1);
        while (!q.empty()) {
            auto [d,u,st]=q.top(); q.pop();
            if (u==dst) return d;
            if (st==0 || d>dist[u][st]) continue;
            for (auto [v,w] : g[u])
                if (d+w<dist[v][st-1]) {
                    dist[v][st-1]=d+w;
                    q.emplace(d+w, v, st-1);
                }
        }
        return -1;
    }
};
