/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb(elem_)				push_back(elem_)
#define mp(first_, second_)		make_pair(first_, second_)

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& a_i : a)
		cin >> a_i;

	vector<int> cnt(n);
	for (int i = 0; i < n; ++i)
		if (a[i] == 0)
			++cnt[i];
		else { // a[i] > 0
			if (i - a[i] >= 0)
				++cnt[i - a[i]];
			if (i + a[i] < n)
				++cnt[i + a[i]];
		}

	auto p = max_element(cnt.begin(), cnt.end());
	int m = *p;
	int c = (int)count(cnt.begin(), cnt.end(), m);

	cout << m << '\n';
	if (c == 1)
		cout << p - cnt.begin() + 1 << '\n';
}
