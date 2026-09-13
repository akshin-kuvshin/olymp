// author: Danila "akshin_" Axyonov

#include <iostream>
#include <unordered_map>
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
    unordered_map<lli, lli> m;
    while (n--) {
        lli num;
        cin >> num;
        ++m[num];
    }
    lli k,
        groups = 0LL,
        ans = 0LL;
    do {
        k = 0LL;
        ++groups;
        for (auto [num, cnt] : m) {
            if (cnt - groups < 0LL)
                continue;
            ++k;
        }
        ans += k * (k - 1LL) / 2LL;
    } while (k > 0LL);
    cout << ans << '\n';
}

/*
a1 < a2 < a3 < ... < a(n - 1) < an
ans = (n - 1) + (n - 2) + ... + 1 = n(n - 1)/2

n1, n2, ..., nk
ans = n1(n1 - 1)/2 + n2(n2 - 1)/2 + ... + nk(nk - 1)/2
*/
