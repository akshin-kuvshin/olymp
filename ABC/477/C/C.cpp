// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli q;
    cin >> q;
    string s,
           t;
    cin >> s >> t;
    lli s_size = (lli)s.size(),
        t_size = (lli)t.size();

    vector<lli> b;
    for (int i = 0; i + (int)t_size <= (int)s_size; ++i) {
        bool f = true;
        for (int j = 0; j < (int)t_size; ++j)
            if (s[i + j] != t[j]) {
                f = false;
                break;
            }
        if (f)
            b.pb((lli)i);
    }

    while (q--) {
        lli l,
            r;
        cin >> l >> r;
        --l;

        auto p = lower_bound(b.begin(), b.end(), l);
        cout << (p != b.end() and *p + t_size <= r ? "Yes" : "No") << '\n';
    }
}
