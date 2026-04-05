#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // min-heap storing {node, dist}, ordered by dist (second)
        auto cmp = [](const pair<int,int> &a, const pair<int,int> &b){
            return a.second > b.second; // smaller second => higher priority
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> heap(cmp);

        // adjacency: node -> list of {neighbour, weight}
        unordered_map<int, vector<pair<int,int>>> adj_list;

        // current best known time to node (acts like dist[])
        unordered_map<int,int> time;

        const int INF = 1'000'000'000;

        // fill adj list
        for (auto &e : times) {
            int u = e[0], v = e[1], w = e[2];
            adj_list[u].push_back({v, w});
        }

        // initialize start node
        heap.push({k, 0});
        time[k] = 0;

        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int u = t.first;
            int d = t.second;

            // STALE-ENTRY GUARD: if this popped distance is worse than
            // the best known, skip processing its neighbours.
            if (time.count(u) && d > time[u]) continue;

            // if node has no outgoing edges, adj_list[u] will be empty (fine)
            for (auto &neighbour : adj_list[u]) {
                int v = neighbour.first;
                int w = neighbour.second;

                if (!time.count(v)) time[v] = INF; // initialize if unseen

                if (d + w < time[v]) {
                    time[v] = d + w;           // update best known time
                    heap.push({v, time[v]});   // push new candidate
                }
            }
        }

        // check reachability for all nodes 1..n and compute max time
        int ans = 0;
        for (int node = 1; node <= n; ++node) {
            if (!time.count(node)) return -1; // unreachable
            ans = max(ans, time[node]);
        }
        return ans;
    }
};