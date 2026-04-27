// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_set>
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

    lli q;
    cin >> q;
    while (q--)
        solve();

    return 0;
}

void solve() {
    lli n;
    cin >> n;
    vector<lli> a(n);
    unordered_set<lli> s;
    for (auto& ai : a) {
        cin >> ai;
        s.insert(ai);
    }

    if ((lli)s.size() < n) {
        cout << "-1\n";
        return;
    }

    sort(a.begin(), a.end(), greater<lli>());
    for (auto ai : a)
        cout << ai << ' ';
    cout << '\n';
}
