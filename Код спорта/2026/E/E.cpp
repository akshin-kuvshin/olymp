/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikolay Osipenko.
 */

#include <iostream>
#include <vector>
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
        m;
    cin >> n >> m;
    vector<lli> a(n),
                b(m);
    for (auto& ai : a)
        cin >> ai;
    for (auto& bi : b)
        cin >> bi;

    bool zeros_in_a = false,
         zeros_in_b = false;
    for (auto ai : a)
        if (ai == 0LL) {
            zeros_in_a = true;
            break;
        }
    for (auto bi : b)
        if (bi == 0LL) {
            zeros_in_b = true;
            break;
        }

    lli ans;
    if (not zeros_in_a and not zeros_in_b)
        ans = n + m - 2LL;
    else if (zeros_in_a and not zeros_in_b)
        ans = n - 1LL;
    else if (not zeros_in_a and zeros_in_b)
        ans = m - 1LL;
    else {
        lli al,
            ar,
            bl,
            br;
        for (int i = 0; i < (int)n; ++i)
            if (a[i] == 0LL) {
                al = (lli)i;
                break;
            }
        for (int i = (int)n - 1; i >= 0; --i)
            if (a[i] == 0LL) {
                ar = (n - 1LL) - (lli)i;
                break;
            }
        for (int j = 0; j < (int)m; ++j)
            if (b[j] == 0LL) {
                bl = (lli)j;
                break;
            }
        for (int j = (int)m - 1; j >= 0; --j)
            if (b[j] == 0LL) {
                br = (m - 1LL) - (lli)j;
                break;
            }
        ans = min(al, bl) + min(ar, br);
    }
    cout << ans << '\n';
}
