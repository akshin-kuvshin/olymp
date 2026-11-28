// author: Danila "akshin_" Axyonov
// O(m^4 * (n + m)) - so slow...

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define mp(_first, _second)     make_pair(_first, _second)
#define pb(_elem)               push_back(_elem)

void solve();
bool connected(const vector<vector<plli>>& G, lli n, const unordered_set<lli>& removed_ribs);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        m;
    cin >> n >> m;
    vector<vector<plli>> G(n);
    for (int i = 0; i < (int)m; ++i) {
        lli u,
            v;
        cin >> u >> v;
        --u; --v;
        G[u].pb(mp(v, (lli)i));
        G[v].pb(mp(u, (lli)i));
    }

    if (not connected(G, n, {})) {
        cout << "0 1\n";
        return;
    }

    lli cnt = 0LL;

    for (int i = 0; i < (int)m; ++i)
        if (not connected(G, n, { (lli)i }))
            ++cnt;
    if (cnt) {
        cout << "1 " << cnt << '\n';
        return;
    }

    for (int i = 0; i < (int)m; ++i)
        for (int j = i + 1; j < (int)m; ++j)
            if (not connected(G, n, { (lli)i, (lli)j }))
                ++cnt;
    if (cnt) {
        cout << "2 " << cnt << '\n';
        return;
    }

    for (int i = 0; i < (int)m; ++i)
        for (int j = i + 1; j < (int)m; ++j)
            for (int k = j + 1; k < (int)m; ++k)
                if (not connected(G, n, { (lli)i, (lli)j, (lli)k }))
                    ++cnt;
    if (cnt) {
        cout << "3 " << cnt << '\n';
        return;
    }

    for (int i = 0; i < (int)m; ++i)
        for (int j = i + 1; j < (int)m; ++j)
            for (int k = j + 1; k < (int)m; ++k)
                for (int l = k + 1; l < (int)m; ++l)
                    if (not connected(G, n, { (lli)i, (lli)j, (lli)k, (lli)l }))
                        ++cnt;
    if (cnt) {
        cout << "4 " << cnt << '\n';
        return;
    }

    cout << "-1\n";
}

bool connected(const vector<vector<plli>>& G, lli n, const unordered_set<lli>& removed_ribs) {
    queue<lli> q;
    vector<bool> used(n);

    q.push(0LL);
    used.front() = true;
    while (not q.empty()) {
        lli v = q.front();
        q.pop();

        for (auto [nb, rib_id] : G[v]) {
            if (removed_ribs.contains(rib_id))
                continue;
            if (used[nb])
                continue;

            q.push(nb);
            used[nb] = true;
        }
    }

    return all_of(used.begin(), used.end(), [](bool used_) { return used_; });
}
