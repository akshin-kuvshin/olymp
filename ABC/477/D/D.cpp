// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli INF = (lli)1e18 + 1LL;

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
    vector<vector<plli>> a(n, vector<plli>(1, mp(0LL, INF)));

    lli q;
    cin >> q;
    vector<pair<lli, char>> color_queries;
    for (lli t = 1LL; t <= q; ++t) {
        lli cmd;
        cin >> cmd;
        if (cmd == 1LL) {
            lli x;
            cin >> x;
            --x;
            if (a[x].back().second == INF)
                a[x].back().second = t;
            else // a[x].back().second < INF
                a[x].pb(mp(t, INF));
        } else { // cmd == 2LL
            char c;
            cin >> c;
            color_queries.pb(mp(t, c));
        }
    }

    for (const auto& a_i : a) {
        lli a_i_size = (lli)a_i.size();
        bool f = false;
        for (int j = (int)a_i_size - 1; j >= 0; --j) {
            auto p = --upper_bound(color_queries.begin(), color_queries.end(), mp(a_i[j].second, '\0'));
            if (next(p) == color_queries.begin())
                continue;
            if (a_i[j].first < p->first) {
                cout << p->second;
                f = true;
                break;
            }
        }
        if (not f)
            cout << 'a';
    }
    cout << '\n';
}
