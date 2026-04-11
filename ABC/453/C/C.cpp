// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
using namespace std;
using lli = long long int;
using plli = pair<lli, lli>;

#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();
void dfs(const vector<lli>& a, lli n, vector<bool>& dir, lli i, lli& ans);
bool sign(lli x);

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

    lli ans = 0LL;
    vector<bool> dir(n);
    dfs(a, n, dir, 0LL, ans);
    cout << ans << '\n';
}

void dfs(const vector<lli>& a, lli n, vector<bool>& dir, lli i, lli& ans) {
    if (i == n) {
        lli pos = 0LL,
            cnt = 0LL;
        for (int j = 0; j < (int)n; ++j) {
            bool old_sign = sign(pos);
            pos += a[j] * (dir[j] ? 1LL : -1LL);
            bool new_sign = sign(pos);
            cnt += (lli)(old_sign xor new_sign);
        }
        ans = max(ans, cnt);
        return;
    }

    dir[i] = false;
    dfs(a, n, dir, i + 1LL, ans);
    dir[i] = true;
    dfs(a, n, dir, i + 1LL, ans);
}

bool sign(lli x) {
    return x >= 0LL;
}
