// https://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) x.begin(), x.end()
#define print_array(arr) for (auto it: arr) cout << it << " "; cout << endl;

int getTheMaximumRestaurants(int n, int m, vector<int> cats, vector<vector<int>> adj) {
    int ans = 0;
    deque<pair<int, int>> que;
    que.push_back({1, cats[1]});
    vector<int> visited(n + 1, 0);
    visited[1] = 1;

    while (!que.empty()) {
        pair<int, int> it = que.front();
        que.pop_front();
        visited[it.first] = 1;

        if (it.second > m) {
            continue;
        }
        bool isLeaf = true;
        for (int nei: adj[it.first]) {
            if (!visited[nei]) {
                isLeaf = false;
                que.pb({nei, cats[nei] ? it.second + 1 : 0});
            }
        }
        if (isLeaf) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cats(n + 1);

    for (int i=1; i<=n; i++) {
        cin >> cats[i];
    }
    // print_array(cats);
    vector<vector<int>> adj(n + 1);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cout << getTheMaximumRestaurants(n, m, cats, adj);

    return 0;
}