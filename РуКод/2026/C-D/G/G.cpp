/* authors:
1) Danila "akshin_" Axyonov;
2) Alexander "Valeev_Alex" Valeev;
3) Nikita "benchik_228" Terebinov.
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
    string s;
    cin >> s;

    if (s == "encode") {
        lli n,
            q;
        cin >> n >> q;
        while (q--) {
            vector<lli> a(3);
            for (auto& a_i : a)
                cin >> a_i;
            sort(a.begin(), a.end());
            lli i = a[0],
                j = a[1];
            if ((i & 1LL) == (j & 1LL))
                cout << i << ' ' << j << '\n';
            else {
                lli ii = n - j,
                    jj = n - i + 1LL;
                cout << ii << ' ' << jj << '\n';
            }
        }
    } else { // s == "decode"
        lli n,
            q;
        cin >> n >> q;
        while (q--) {
            lli i,
                j;
            cin >> i >> j;
            if (i + j > n)
                cout << i << ' ' << j << ' ' << n << '\n';
            else { // i + j <= n
                lli ii = n - j + 1LL,
                    jj = n - i;
                cout << ii << ' ' << jj << ' ' << n << '\n';
            }
        }
    }
}
