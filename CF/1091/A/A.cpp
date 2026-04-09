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
        k;
    cin >> n >> k;
    vector<lli> a(n);
    for (lli& ai : a)
        cin >> ai;

    lli sum = 0LL;
    for (lli ai : a)
        sum += ai;

    cout << (sum % 2LL == 1LL or n * k % 2LL == 0LL ? "YES" : "NO") << '\n';
}
