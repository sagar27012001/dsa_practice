//https://codeforces.com/contest/1144/problem/F

/*
Input :
6 5
1 5
2 1
1 4
3 1
6 1

nodes = 6
edges = 5

adj = {
    1 => [5, 2, 4, 3, 6]
    2 => [1]
    3 => [1]
    4 => [1]
    5 => [1]
    6 => [1]
}

ex2
4 4
1 2
2 3
3 4
4 1

n = 4
e = 4
adj = {
    1 => [2,4]
    2 => [1,3]
    3 => [2,4]
    4 => [3,1]
}

1 -> 2, 4
3 -> 2, 4
Basically we have to check if the given undirected graph is bipartite or not ?
*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back


void solve(int &v, vector<vector<int>> &adj, vector<pair<int, int>> &edges) {
    vector<int> color(v+1, -1);
    queue<int> que;

    for (int start=1; start<=v; start++) {
        if (color[start] != -1) continue;

        que.push(start);
        color[start] = 1;

        while (!que.empty()) {
            int node = que.front();
            que.pop();
            for (int nei: adj[node]) {
                if (color[nei] == -1) {
                    color[nei] = 1 - color[node];
                    que.push(nei);
                } else if (color[nei] == color[node]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    for (auto it: edges) {
        if (color[it.first] == 0 && color[it.second] == 1) cout << "0";
        else cout << "1";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;


    vector<vector<int>> adj(v + 1);

    vector<pair<int, int>> edges;

    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u, v});
    }

    solve(v, adj, edges);

    return 0;
}