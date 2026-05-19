/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <string>
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
    string s;
    cin >> s;
    lli ans = 0LL;
    for (auto c : s) {
        if (c < '0' or '9' < c)
            continue;
        ans += (lli)(c - '0');
    }
    cout << ans << '\n';
}
