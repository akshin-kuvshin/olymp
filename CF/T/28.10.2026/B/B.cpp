// author: Danila "akshin_" Axyonov

#include <iostream>
#include <vector>
#include <deque>
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
    vector<lli> p(n);
    for (auto& p_i : p)
        cin >> p_i;
    deque<lli> dq;
    dq.push_back(p.front());
    for (int i = 1; i < (int)n; ++i)
        if (p[i] < dq.front())
            dq.push_front(p[i]);
        else // p[i] >= dq.front()
            dq.push_back(p[i]);
    for (auto dq_i : dq)
        cout << dq_i << ' ';
    cout << '\n';
}
