#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int lli;

const double INF = 1e30,
             EPS = 1e-6;

struct d3 {
    double x;
    double y;
    double z;
};

void solve();
d3 vec(d3 a, d3 b);
double len(d3 a, d3 b);
double per(d3 a, d3 b, d3 c);

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

    vector<d3> v;
    for (int i = 0; i < (int)n; ++i) {
        double x,
               y,
               z;
        cin >> x >> y >> z;
        d3 l = { x, y, z };
        v.push_back(l);
    }

    double ans = INF;
    for (int i = 1; i < (int)n; ++i)
        for (int j = i + 1; j < (int)n; ++j) {
            d3 a,
               b;
            a = vec(v[0], v[i]);
            b = vec(v[0], v[j]);
            if (abs(a.x / b.x - a.y / b.y) < EPS and abs(a.y / b.y - a.z / b.z) < EPS and a.x / b.x >= 0.)
                ans = min(ans, min(len({ 0., 0., 0. }, a), len({ 0., 0., 0. }, b)));
            else
                ans = min(ans, per(v[0], v[i], v[j]) * .5);
        }

    cout << fixed << setprecision(20) << ans << '\n';
}

d3 vec(d3 a, d3 b) {
    return { b.x - a.x, b.y - a.y, b.z - a.z };
}

double len(d3 a, d3 b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

double per(d3 a, d3 b, d3 c) {
    return (len(a, b) + len(b, c) + len(c, a));
}
