/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikolay Osipenko.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define num first
#define ind second

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
    vector<plli> a(n);
    for (int i = 0; i < (int)n; ++i) {
        cin >> a[i].num;
        a[i].ind = (lli)i;
    }
    sort(a.begin(), a.end());

    lli mx = 0LL;
    for (int i = 0; i < (int)n; ++i)
        if ((lli)i < a[i].ind)
            mx = max(mx, a[i].ind - (lli)i);
    cout << mx << '\n';
}
