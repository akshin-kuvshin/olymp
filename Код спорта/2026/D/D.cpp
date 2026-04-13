/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikolay Osipenko.
 */

#include <iostream>
using namespace std;
typedef long long int lli;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        k;
    cin >> n >> k;

    lli ans = 0LL;

    lli t1 = n / k;
    ans += t1 * t1 * t1;

    if (k % 2LL == 0LL) {
        lli t2 = 2LL * n / k;
        t2 -= t1;
        ans += t2 * t2 * t2;
    }

    cout << ans << '\n';
}
