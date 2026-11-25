// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

const int LOG = 30;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}

void solve() {
    lli a,
        b;
    cin >> a >> b;

    lli ans = 0LL;
    for (int i = 30; i >= 0; --i) {
        lli c = (1LL << i);
        if ((a & c) != (b & c))
            ans += c;
    }

    cout << ans << '\n';
}
