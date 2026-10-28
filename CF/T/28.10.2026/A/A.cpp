// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

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
    lli d = n / 3LL,
        r = n % 3LL;
    lli c1 = d,
        c2 = d;
    if (r == 1LL)
        ++c1;
    else if (r == 2LL)
        ++c2;
    cout << c1 << ' ' << c2 << '\n';
}
