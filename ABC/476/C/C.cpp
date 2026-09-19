// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <set>
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
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (auto& ai : a)
        cin >> ai;
    multiset<lli> s;
    s.insert(a[0]);
    s.insert(a[1]);
    for (int i = 2; i < (int)n; ++i) {
        s.insert(a[i]);
        cout << *prev(s.end(), 3) << '\n';
    }
}
