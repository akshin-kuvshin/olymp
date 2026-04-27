// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

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
    lli n,
        m;
    cin >> n >> m;
    vector<lli> a(n);
    for (auto& ai : a)
        cin >> ai;

    lli cur = -1LL,
        len = 0LL;
    for (auto ai : a)
        if (ai != cur) {
            if (len >= m) {
                cout << "NO\n";
                return;
            }
            cur = ai;
            len = 1LL;
        } else
            ++len;
    cout << (len < m ? "YES" : "NO") << '\n';
}
