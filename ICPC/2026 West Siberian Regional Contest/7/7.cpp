/* authors:
 * 1) Danila "akshin_" Axyonov;
 * [!!!] 2) Alexander "Valeev_Alex" Valeev; [!!!]
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

#define pb(_elem)               push_back(_elem)

const lli MOD = 2'095'133'040LL;
lli state;

void solve();
lli my_rand(lli a, lli b);
vector<lli> shake(const vector<lli>& p, lli n, lli a, lli b, lli state_0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        a,
        b;
    cin >> n >> a >> b;
    if (a == 0LL and b == 0LL) {
        cout << "1\n";
        return;
    }

    vector<lli> p(n);
    for (int i = 0; i < (int)n; ++i)
        p[i] = (lli)(i + 1);

    lli n_fact = 1LL;
    for (lli k = 2LL; k <= n; ++k)
        n_fact = (n_fact * k) % MOD;
    if (n_fact == 0LL)
        n_fact = MOD;

    vector<lli> small,
                large;
    for (lli k1 = 2LL; k1 * k1 <= n_fact; ++k1) {
        if (n_fact % k1)
            continue;
        lli k2 = n_fact / k1;

        small.pb(k1);
        if (k2 != k1)
            large.pb(k2);
    }

    const auto check = shake(p, n, a, b, 1LL);

    for (auto k : small)
        if (shake(p, n, a, b, k + 1LL) == check) {
            if (k == 2LL and shake(p, n, a, b, 2LL) == check) {
                cout << "1\n";
                return;
            }
            cout << k << '\n';
            return;
        }

    reverse(large.begin(), large.end());
    for (auto k : large)
        if (shake(p, n, a, b, k + 1LL) == check) {
            cout << k << '\n';
            return;
        }

    cout << n_fact << '\n';
}

lli my_rand(lli a, lli b) {
    return state = (a * state + b) % MOD;
}

vector<lli> shake(const vector<lli>& p, lli n, lli a, lli b, lli state_0) {
    auto c = p;
    state = state_0;
    for (lli i = n - 1LL; i > 0LL; --i) {
        lli j = my_rand(a, b) % (i + 1LL);
        swap(c[i], c[j]);
    }
    return c;
}
