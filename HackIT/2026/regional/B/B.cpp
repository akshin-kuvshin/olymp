/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
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
        m,
        a,
        b;
    cin >> n >> m >> a >> b;
    lli ans = (n + a - 1LL) / a + (m + b - 1LL) / b;
    cout << ans << '\n';
}
