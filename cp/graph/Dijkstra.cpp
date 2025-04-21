//https://codeforces.com/contest/20/problem/C
/*
The graph may contain self loop and multiple edges
so remove the self loop and take the min distance edges between multiple edges
that would make the graph simply undirected and we can use Dijkstra's algorithm to find min distance.


    1----2-------5
    |    |      /
    |    |     /
    |    |    /
    4----3---/
*/
#include <bits/stdc++.h>
using namespace std;

void solve(int &v, vector<vector<pair<int, int>>> &adj) {
    auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
        return a.first > b.first;
    };
    vector<int> parent(v+1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    pq.push({0, 1});
    vector<int> dist(v+1, INT_MAX);
    dist[1] = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        for (pair<int, int> nei: adj[it.second]) {
            if (dist[nei.first] > it.first + nei.second) {
                dist[nei.first] = it.first + nei.second;
                pq.push({dist[nei.first], nei.first});
                parent[nei.first] = it.second;
            }
        }
    }
    if (dist[v] == INT_MAX) {
        cout << "-1\n";
        return;
    }
    vector<int> op;
    for (int i=v; i != -1; i=parent[i]) {
        op.push_back(i);
    }
    reverse(op.begin(), op.end());
    for (int n: op) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;

    cin >> v >> e;
    vector<vector<pair<int, int>>> adj(v+1); // adj[u] = [[v, dist]

    for (int i=0; i<e; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        if (u != v) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    solve(v, adj);
    return 0;
}