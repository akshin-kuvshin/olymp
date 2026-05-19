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
typedef pair<lli, lli> plli;
#define a first
#define b second

void solve();
lli f(lli n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    lli ans = 0LL;
    for (lli i = 1LL; i <= n; ++i)
        ans += f(i);
    cout << ans << '\n';
}

lli f(lli n) {
    lli ans = 0LL;

    lli th = n / 1'000LL;
    n %= 1'000LL;
    ans += th * 4LL;

    lli hu = n / 100LL;
    n %= 100LL;
    if (hu == 1LL)
        ans += 2LL;
    else if (hu == 5LL)
        ans += 3LL;
    else if (hu == 2LL)
        ans += 4LL;
    else if (hu == 4LL or hu == 6LL)
        ans += 5LL;
    else if (hu == 3LL or hu == 9LL)
        ans += 6LL;
    else if (hu == 7LL)
        ans += 7LL;
    else if (hu == 8LL)
        ans += 9LL;

    lli te = n / 10LL;
    n %= 10LL;
    if (te == 1LL or te == 5LL)
        ans += 2LL;
    else if (te == 2LL or te == 4LL or te == 6LL or te == 9LL)
        ans += 4LL;
    else if (te == 3LL or te == 7LL)
        ans += 6LL;
    else if (te == 8LL)
        ans += 8LL;

    if (n == 1LL)
        ans += 1LL;
    else if (n == 2LL or n == 5LL)
        ans += 2LL;
    else if (n == 3LL or n == 4LL or n == 6LL or n == 9LL)
        ans += 3LL;
    else if (n == 7LL)
        ans += 4LL;
    else if (n == 8LL)
        ans += 5LL;

    return ans;
}
