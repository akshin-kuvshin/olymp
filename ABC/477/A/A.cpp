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
    unordered_map<char, char> next_;
    next_['B'] = 'Y';
    next_['Y'] = 'R';
    next_['R'] = 'B';

    char c;
    cin >> c;
    cout << next_[c] << '\n';
}
