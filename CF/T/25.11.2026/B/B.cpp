// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

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
    lli x,
        y,
        k;
    cin >> x >> y >> k;

    lli ans = (k + y * k - 1LL + x - 2LL) / (x - 1LL) + k;

    cout << ans << '\n';
}
