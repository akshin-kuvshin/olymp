// author: Danila "akshin_" Axyonov
// this code is not slower than O(nk)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli INF = (lli)1e18 + 1LL;

void solve();
lli dfs(lli i, const lli n, lli j, const lli k, const vector<lli>& prefix, const lli each);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    lli n,
        k;
    string s;
    cin >> n >> k >> s;
    vector<lli> a(n);
    for (int i = 0; i < (int)n; ++i)
        a[i] = (lli)(s[i] - '0');

    vector<lli> prefix(n + 1LL);
    for (int i = 0; i < (int)n; ++i)
        prefix[i + 1] = prefix[i] + a[i];
    lli each = prefix.back() / k;
    lli ans = dfs(0LL, n, 0LL, k, prefix, each);

    cout << ans << '\n';
}

unordered_map<lli, unordered_map<lli, lli>> cache;
lli dfs(lli i, const lli n, lli j, const lli k, const vector<lli>& prefix, const lli each) {
    if (j == k)
        return 0LL;
    if (prefix.back() - prefix[i] < (k - j) * each)
        return INF;
    if (cache.contains(i) and cache[i].contains(j))
        return cache[i][j];

    lli res = dfs(i + 1LL, n, j, k, prefix, each);
    if (prefix[i + 1LL] - prefix[i] == 1LL) { // a[i] == 1LL
        lli i1 = (lli)(lower_bound(prefix.begin(), prefix.end(), prefix[i] + each) - prefix.begin());
        res = min(
            res,
            (i1 - i) + dfs(i1, n, j + 1LL, k, prefix, each)
        );
    }
    return cache[i][j] = res;
}
