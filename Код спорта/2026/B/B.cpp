/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "ValeevAlex" Valeev;
 * 3) Nikolay Osipenko.
 */

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pi;

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

    lli ans = 0LL;
    vector<pi> d = { {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2} };
    for (int i = 1; i <= min(2, (int)n); ++i)
        for (int j = 1; j <= (int)n; ++j) {
            lli cnt = 0LL;
            for (auto di : d) {
                int ii = i + di.first,
                    jj = j + di.second;
                cnt += (lli)(1 <= ii and ii <= (int)n and 1 <= jj and jj <= (int)n);
            }
            ans += n * n - cnt - 1LL;
        }
    for (int i = max((int)n - 1, 3); i <= (int)n; ++i)
        for (int j = 1; j <= (int)n; ++j) {
            lli cnt = 0LL;
            for (auto di : d) {
                int ii = i + di.first,
                    jj = j + di.second;
                cnt += (lli)(1 <= ii and ii <= (int)n and 1 <= jj and jj <= (int)n);
            }
            ans += n * n - cnt - 1LL;
        }
    for (int j = 1; j <= min(2, (int)n); ++j)
        for (int i = 3; i <= (int)n - 2; ++i) {
            lli cnt = 0LL;
            for (auto di : d) {
                int ii = i + di.first,
                    jj = j + di.second;
                cnt += (lli)(1 <= ii and ii <= (int)n and 1 <= jj and jj <= (int)n);
            }
            ans += n * n - cnt - 1LL;
        }
    for (int j = max((int)n - 1, 3); j <= (int)n; ++j)
        for (int i = 3; i <= (int)n - 2; ++i) {
            lli cnt = 0LL;
            for (auto di : d) {
                int ii = i + di.first,
                    jj = j + di.second;
                cnt += (lli)(1 <= ii and ii <= (int)n and 1 <= jj and jj <= (int)n);
            }
            ans += n * n - cnt - 1LL;
        }
    if (n > 4LL)
        ans += (n - 4LL) * (n - 4LL) * (n * n - 9LL);
    ans /= 2LL;
    cout << ans << '\n';
}
