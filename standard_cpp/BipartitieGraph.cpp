#include<bits/stdc++.h>
using namespace std;

#define pb push_back


void isBipartite(int &v, vector<vector<int>> &adj) {
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
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;


    vector<vector<int>> adj(v + 1);

    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    isBipartite(v, adj);

    return 0;
}