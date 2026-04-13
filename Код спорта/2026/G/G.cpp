/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikolay Osipenko.
 */

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    lli q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}

void solve() {
    lli a,
        b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);

    if (a == b)
        cout << "first";
    else if (a == 1LL and b == 2LL)
        cout << "second";
    else if (b - a == 1LL)
        cout << "first";
    else if (a == 1LL && b > 2LL)
        cout << "first";
    else if (a == 2LL && b > 3LL)
        cout << "first";
    else {
        set<plli> bad_pairs = { { 3LL, 5LL } };
        unordered_set<lli> bad_i = { 5LL };
        for (lli i = 4LL; i <= a; ++i) {
            if (bad_i.contains(i))
                continue;
            lli j = i + (--bad_pairs.end())->second - (--bad_pairs.end())->first + 1LL;
            bad_pairs.insert({ i, j });
            bad_i.insert(j);
        }
        cout << (bad_pairs.contains({ a, b }) ? "second" : "first");
    }
    cout << '\n';
}
