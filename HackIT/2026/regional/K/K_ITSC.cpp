// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
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

    solve();

    return 0;
}

void solve() {
    lli n,
        m,
        k;
    cin >> n >> m >> k;
    vector<lli> a(n),
                b(m);
    for (auto& ai : a)
        cin >> ai;
    for (auto& bi : b)
        cin >> bi;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    lli r = m - 1LL,
        ans = 0LL;
    for (int l = 0; l < (int)n; ++l) {
        while (r >= 0LL and a[l] + b[r] > k)
            --r;
        ans += (m - 1LL) - r;
    }
    cout << ans << '\n';
}

/*
k = 5

           l
a = [1 2 3 4]
b = [1 1 2 3]
       r
ans = 1 + 2 = 3

a[l] + b[r + 1] > k
a[l + 1] + b[r + 1] >= a[l] + b[r + 1] > k
*/
