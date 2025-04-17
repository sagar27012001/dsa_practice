// https://codeforces.com/problemset/problem/977/E
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

bool isCyclicComponent(int &node, vector<vector<int>> &adj, vector<int> &visited) {
    deque<int> que;
    que.push_back(node);
    visited[node] = 1;

    bool isCycle = true;

    while (!que.empty()) {
        int node = que.front();
        que.pop_front();
        
        if (adj[node].size() != 2)
            isCycle = false;
        
        for (int nei: adj[node])  {
            if (!visited[nei]) {
                que.push_back(nei);
                visited[nei] = 1;
            }
        }
    }

    return isCycle;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n+1);

    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    int ans = 0;
    vector<int> visited(n+1, 0);

    for (int i=1; i<=n; i++) {
        if (!visited[i] && isCyclicComponent(i, adj, visited)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}