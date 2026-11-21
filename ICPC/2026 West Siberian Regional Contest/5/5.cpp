/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long int lli;

#define pb(elem_)				push_back(elem_)
#define mp(first_, second_)		make_pair(first_, second_)

vector<lli> fact;

void solve();
lli p(const vector<lli>& v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fact.pb(1LL);
	for (lli n = 1LL; n <= 20LL; ++n)
		fact.pb(fact.back() * n);

	solve();

	return 0;
}

void solve() {
	string s;
	cin >> s;
	vector<lli> a;
	for (auto c : s)
		a.pb((lli)(c - 'a'));

	lli ans = 1LL;
	while (not a.empty()) {
		unordered_set<lli> used;
		for (int i = 1; i < (int)a.size(); ++i)
			if (a[i] < a.front() and not used.contains(a[i])) {
				vector<lli> b;
				for (int j = 0; j < (int)a.size(); ++j) {
					if (j == i)
						continue;
					b.pb(a[j]);
				}
				ans += p(b);
				used.insert(a[i]);
			}
		a.erase(a.begin());
	}
	cout << ans << '\n';
}

lli p(const vector<lli>& v) {
	unordered_map<lli, lli> m;
	for (auto v_i : v)
		++m[v_i];
	lli res = fact[v.size()];
	for (auto [_, cnt] : m)
		res /= fact[cnt];
	return res;
}
