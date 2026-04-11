// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
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
    string s;
    cin >> n >> s;

    bool flag = false;
    for (auto c : s)
        if (flag or c != 'o') {
            cout << c;
            flag = true;
        }
    cout << '\n';
}
