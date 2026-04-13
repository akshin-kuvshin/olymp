/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikolay Osipenko.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

void solve();

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
    vector<plli> ribs(m);
    for (auto& ribsi : ribs)
        cin >> ribsi.first >> ribsi.second;

    vector<unordered_set<lli>> G(n + 1LL);
    for (auto ribsi : ribs) {
        G[ribsi.first].insert(ribsi.second);
        G[ribsi.second].insert(ribsi.first);
    }

    vector<unordered_set<lli>> order(n + 1LL);
    queue<lli> q;
    vector<bool> used(n + 1LL);
    for (lli u = 1LL; u <= n; ++u) {
        if (used[u])
            continue;
        q.push(u);
        used[u] = true;
        while (not q.empty()) {
            lli cur = q.front();
            q.pop();
            for (lli nb : G[cur]) {
                if (order[nb].contains(cur))
                    continue;
                order[cur].insert(nb);
                if (used[nb])
                    continue;
                q.push(nb);
                used[nb] = true;
            }
        }
    }

    for (auto& ribsi : ribs) {
        if (order[ribsi.second].contains(ribsi.first))
            swap(ribsi.first, ribsi.second);
        cout << ribsi.first << ' ' << ribsi.second << '\n';
    }
}
