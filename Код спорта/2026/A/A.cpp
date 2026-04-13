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
    lli k;
    cin >> k;
    lli even = k / 2LL,
        odd = (k + 1LL) / 2LL;
    cout << even * odd << '\n';
}
