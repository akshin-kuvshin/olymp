/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikita "rizhiy" Terebinov.
 */

#include <iostream>
#include <vector>
#include <map>
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
    map<lli, lli> m;
    while (n--) {
        lli tmp;
        cin >> tmp;
        ++m[tmp];
    }
    lli ans = 0LL;
    while (not m.empty()) {
        vector<lli> l;
        for (auto& p : m)
            l.push_back(p.first);
        lli len = (lli)l.size();
        ans += len * (len - 1LL) / 2LL;
        for (auto li : l) {
            --m[li];
            if (m[li] == 0LL)
                m.erase(li);
        }
    }
    cout << ans << '\n';
}
