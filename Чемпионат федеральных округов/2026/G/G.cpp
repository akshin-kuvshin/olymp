// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long int lli;

const lli N = 4LL;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    vector<vector<tuple<string, lli, lli>>> a(N);
    vector<lli> a_size(N);
    for (int i = 0; i < (int)N; ++i) {
        cin >> a_size[i];
        a[i].resize(a_size[i]);
        for (auto& a_i_j : a[i])
            cin >> get<0>(a_i_j);
        for (auto& a_i_j : a[i])
            cin >> get<1>(a_i_j);
        for (auto& a_i_j : a[i])
            cin >> get<2>(a_i_j);
    }

    for (int x = 0; x < (int)a_size[0]; ++x)
        for (int y = 0; y < (int)a_size[1]; ++y)
            for (int z = 0; z < (int)a_size[2]; ++z)
                for (int t = 0; t < (int)a_size[3]; ++t) {
                    vector<lli> ls = {
                        get<1>(a[0][x]),
                        get<1>(a[1][y]),
                        get<1>(a[2][z]),
                        get<1>(a[3][t])
                    };
                    vector<lli> rs = {
                        get<2>(a[0][x]),
                        get<2>(a[1][y]),
                        get<2>(a[2][z]),
                        get<2>(a[3][t])
                    };
                    lli l = *max_element(ls.begin(), ls.end()),
                        r = *min_element(rs.begin(), rs.end());
                    if (l <= r)
                        cout << get<0>(a[0][x]) << ' ' << get<0>(a[1][y]) << ' ' << get<0>(a[2][z]) << ' ' << get<0>(a[3][t]) << '\n';
                }
}
