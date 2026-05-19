/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
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
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& ai : a)
        cin >> ai;
    lli m;
    cin >> m;
    unordered_set<lli> bad_i;
    while (m--) {
        lli tmp;
        cin >> tmp;
        bad_i.insert(--tmp);
    }
    lli ans = 0LL;
    for (int i = 0; i < (int)n; ++i) {
        if (bad_i.contains((lli)i))
            continue;
        ans += a[i];
    }
    cout << ans << '\n';
}
