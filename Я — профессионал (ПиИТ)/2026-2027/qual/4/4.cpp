// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
typedef long long int lli;

const lli COLORS = 4LL;

void solve();
void dfs(lli i, lli n, vector<lli>& c, const vector<vector<lli>>& G, lli& ans3, lli& ans4);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    vector<vector<lli>> G = {
        { 1LL, 2LL }, // 0
        { 0LL, 2LL, 3LL, 4LL }, // 1
        { 0LL, 1LL, 4LL, 5LL }, // 2
        { 1LL, 4LL, 6LL, 7LL }, // 3
        { 1LL, 2LL, 3LL, 5LL, 7LL, 8LL }, // 4
        { 2LL, 4LL, 8LL, 9LL }, // 5
        { 3LL, 7LL, 10LL, 11LL }, // 6
        { 3LL, 4LL, 6LL, 8LL, 11LL, 12LL }, // 7
        { 4LL, 5LL, 7LL, 9LL, 12LL, 13LL }, // 8
        { 5LL, 8LL, 13LL, 14LL }, // 9
        { 6LL, 11LL }, // 10
        { 6LL, 7LL, 10LL, 12LL }, // 11
        { 7LL, 8LL, 11LL, 13LL }, // 12
        { 8LL, 9LL, 12LL, 14LL }, // 13
        { 9LL, 13LL } // 14
    };
    const lli n = 15LL;

    lli ans3 = 0LL,
        ans4 = 0LL;
    vector<lli> c(n);
    dfs(0LL, n, c, G, ans3, ans4);

    ans4 += ans3;
    ans3 /= 4LL; // C(4, 3) = 4! / (3! * (4 - 3)!) = 4! / (3! * 1!) = 4
    cout << ans3 << ' ' << ans4 << '\n';
}

void dfs(lli i, lli n, vector<lli>& c, const vector<vector<lli>>& G, lli& ans3, lli& ans4) {
    if (i == n) {
        for (lli v = 0LL; v < n; ++v)
            for (auto nb : G[v])
                if (c[v] == c[nb])
                    return;

        unordered_set<lli> cs;
        for (auto c_i : c)
            cs.insert(c_i);
        lli cs_size = (lli)cs.size();
        if (cs_size == 3LL)
            ++ans3;
        else if (cs_size == 4LL)
            ++ans4;
        else { // votafa...
            cout << "cs_size = " << cs_size << endl;
            exit(EXIT_FAILURE);
        }
        return;
    }

    for (lli c_i = 0LL; c_i < COLORS; ++c_i) {
        c[i] = c_i;
        dfs(i + 1LL, n, c, G, ans3, ans4);
    }
}
