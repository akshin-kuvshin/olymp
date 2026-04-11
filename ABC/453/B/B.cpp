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

    solve();

    return 0;
}

void solve() {
    lli n,
        x;
    cin >> n >> x;
    ++n;
    vector<lli> a(n);
    for (auto& ai : a)
    cin >> ai;

    lli save = a.front();
    cout << "0 " << save << '\n';
    for (int i = 1; i < (int)n; ++i)
        if (abs(save - a[i]) >= x) {
            save = a[i];
            cout << i << ' ' << save << '\n';
        }
}
