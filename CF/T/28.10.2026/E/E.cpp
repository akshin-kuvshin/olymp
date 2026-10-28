// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

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
    lli n;
    cin >> n;
    vector<plli> a(n);
    vector<lli> cnt(n + 1LL);
    bool duplicate = false;
    for (auto& p : a) {
        cin >> p.first >> p.second;
        ++cnt[p.first];
        ++cnt[p.second];
        duplicate = p.first == p.second;
    }
    for (int i = 1; i <= (int)n; ++i)
        if (cnt[i] != 2LL) {
            cout << "NO\n";
            return;
        }
    if (duplicate) {
        cout << "NO\n";
        return;
    }

    vector<unordered_set<lli>> ind(n + 1LL);
    for (int i = 0; i < (int)n; ++i) {
        ind[a[i].first].insert((lli)i);
        ind[a[i].second].insert((lli)i);
    }
    vector<lli> cnt1(n + 1LL),
                cnt2(n + 1LL);
    queue<plli> q;
    for (int i = 0; i < (int)n; ++i) {
        auto [x1, x2] = a[i];
        if (ind[x1].empty() and ind[x2].empty())
            continue;

        q.push(make_pair((lli)i, 1LL));
        ind[x1].erase((lli)i);
        ind[x2].erase((lli)i);
        while (not q.empty()) {
            auto [j, k] = q.front();
            q.pop();
            auto [y1, y2] = a[j];
            if (k == 1LL) {
                ++cnt1[y1];
                ++cnt1[y2];
            } else {
                ++cnt2[y1];
                ++cnt2[y2];
            }

            if (not ind[y1].empty()) {
                lli nb = *ind[y1].begin();
                auto [z1, z2] = a[nb];
                q.push(make_pair(nb, 3LL - k));
                ind[z1].erase(nb);
                ind[z2].erase(nb);
            }
            if (not ind[y2].empty()) {
                lli nb = *ind[y2].begin();
                auto [z1, z2] = a[nb];
                q.push(make_pair(nb, 3LL - k));
                ind[z1].erase(nb);
                ind[z2].erase(nb);
            }
        }
    }

    bool bad = false;
    for (int i = 1; i <= (int)n; ++i)
        if (not ind[i].empty()) {
            bad = true;
            break;
        }
    if (bad) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= (int)n; ++i)
        if (cnt1[i] != 1LL or cnt2[i] != 1LL) {
            bad = true;
            break;
        }
    if (bad) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
