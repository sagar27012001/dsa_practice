#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define sort(x) sort(all(x))

int getMinimumGroups(int n, vector<int> managers) {
    vector<vector<int>> tree(n + 1);
    vector<int> root;

    rep(emp, 1, n+1) {
        int manager = managers[emp - 1];
        if (manager == -1) root.pb(emp);
        else tree[manager].pb(emp);
    }

    function<int(int)> dfs = [&](int node) {
        int depth = 1;
        for (int nei: tree[node]) {
            depth = max(depth, dfs(nei) + 1);
        }
        return depth;
    };

    int maxDepth = 0;
    for (int emp: root) {
        maxDepth = max(maxDepth, dfs(emp));
    }
    return maxDepth;
}

int main() {
    FAST_IO;
    int n;
    cin >> n;
    vector<int> managers(n);

    rep (i, 0, n) {
        cin >> managers[i];
    }
    cout << getMinimumGroups(n, managers) << endl;
    return 0;
}