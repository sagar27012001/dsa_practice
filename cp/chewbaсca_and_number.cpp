#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

int main()
{
    FAST_IO;

    string x;
    cin >> x;

    for (int i = 0; i < x.size(); ++i) {
        int digit = x[i] - '0';
        int inverted = 9 - digit;

        if (i == 0 && inverted == 0)
            continue;

        if (inverted < digit) {
            x[i] = char(inverted + '0');
        }
    }

    cout << x << "\n";
    return 0;
}