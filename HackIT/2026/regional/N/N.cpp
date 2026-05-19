/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <iomanip>
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
    lli p, i, s, k, a;
    cin >> p >> i >> s >> k >> a;
    lli sex = (p + i) * a - s;
    double ans = 2. * (double)a + (sex <= 0LL ? 0. : (double)sex / (double)k);
    cout << fixed << setprecision(20) << ans << '\n';
}
