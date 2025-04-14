#include <bits/stdc++.h>
using namespace std;

#define FAST_IO              \
    ios::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    FAST_IO

    int n;
    cin >> n;

    int x = 0;
    string op;

    while (n--)
    {
        cin >> op;
        if (op == "++X" || op == "X++")
        {
            x++;
        }
        else if (op == "--X" || op == "X--")
        {
            x--;
        }
    }

    cout << x << "\n";
    return 0;
}