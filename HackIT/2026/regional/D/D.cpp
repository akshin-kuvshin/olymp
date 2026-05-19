/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

class Compare {
public:
    bool operator()(plli p1, plli p2) const {
        if (p1.first != p2.first)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        k;
    cin >> n >> k;
    vector<lli> a(n),
                b(n);
    for (auto& ai : a)
        cin >> ai;
    for (auto& bi : b)
        cin >> bi;

    multiset<plli, Compare> ms;
    for (int i = 0; i < (int)n; ++i)
        ms.insert(make_pair(a[i], b[i]));

    lli ans = 0LL;
    while (k--) {
        plli p = *ms.begin();
        ms.erase(ms.begin());
        ans += p.first;
        p.first -= p.second;
        ms.insert(p);
    }
    cout << ans << '\n';
}
