/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
using namespace std;
typedef long long int lli;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}

void solve() {
	lli n,
		m,
		a,
		b,
		s;
	cin >> n >> m >> a >> b >> s;

	s %= (n + m) << 1;

	lli va = a,
		vb = b,
		vs = s;
	for (int _ = 0; _ < 2; ++_) {
		if (vs > 0LL and va > 0LL and vb == 0LL) {
			lli d = min(va, vs);
			va -= d;
			vs -= d;
		}
		if (vs > 0LL and va == 0LL and vb < m) {
			lli d = min(m - vb, vs);
			vb += d;
			vs -= d;
		}
		if (vs > 0LL and va < n and vb == m) {
			lli d = min(n - va, vs);
			va += d;
			vs -= d;
		}
		if (vs > 0LL and va == n and vb > 0LL) {
			lli d = min(vb, vs);
			vb -= d;
			vs -= d;
		}
	}

	lli pa = a,
		pb = b,
		ps = s;
	for (int _ = 0; _ < 2; ++_) {
		if (ps > 0LL and pa < n and pb == 0LL) {
			lli d = min(n - pa, ps);
			pa += d;
			ps -= d;
		}
		if (ps > 0LL and pa == n and pb < m) {
			lli d = min(m - pb, ps);
			pb += d;
			ps -= d;
		}
		if (ps > 0LL and pa > 0LL and pb == m) {
			lli d = min(pa, ps);
			pa -= d;
			ps -= d;
		}
		if (ps > 0LL and pa == 0LL and pb > 0LL) {
			lli d = min(pb, ps);
			pb -= d;
			ps -= d;
		}
	}

	cout << va << ' ' << vb << '\n' << pa << ' ' << pb << '\n';
}
