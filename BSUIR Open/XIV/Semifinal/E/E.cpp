// author: Alexander "ValeevAlex" Valeev & Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> plli;

#define x first
#define y second

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
    for (auto& ai : a)
        cin >> ai.x >> ai.y;
    sort(a.begin(), a.end());

    vector<plli> v;
    v.push_back(a[0]);
    for (int i = 1; i < (int)n; ++i) {
        bool f = true;
        if (v.back().y > a[i].y) {
            v.push_back(a[i]);
            continue;
        }
        for (auto& vi : v)
            if (vi.y <= a[i].y) {
                vi = a[i];
                f = false;
                break;
            }
        if (f)
            v.push_back(a[i]);
    }

    cout << v.size() << '\n';
}
