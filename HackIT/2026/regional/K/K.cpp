/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <vector>
#include <algorithm>
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
        k;
    cin >> n >> m >> k;
    vector<lli> a(n),
                b(m);
    for (auto& ai : a)
        cin >> ai;
    for (auto& bi : b)
        cin >> bi;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    lli ans = 0LL;
    for (int i = 0; i < (int)n; ++i)
        ans += (lli)(b.end() - upper_bound(b.begin(), b.end(), k - a[i]));
    cout << ans << '\n';
}
