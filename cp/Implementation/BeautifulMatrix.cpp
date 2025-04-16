#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    FAST_IO;
    int ans = -1;
    for (int i=1; i<=5; i++) {
        for (int j=1; j<=5; j++) {
            int n;
            cin >> n;
            if (n == 1) {
                ans = abs(i - 3) + abs(j - 3);
            }
        }
    }
    cout << ans << endl;
    return 0;
}