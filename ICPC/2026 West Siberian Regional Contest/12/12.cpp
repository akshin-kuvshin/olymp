/* authors:
 * 1) Danila "akshin_" Axyonov;
 * 2) Alexander "Valeev_Alex" Valeev;
 * 3) Nikita "benchik_228" Terebinov.
 **/

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define pb(_elem)               push_back(_elem)

const lli SIZE = 20LL;
vector<lli> pow10;

struct num {
    vector<lli> digits;

    num(lli n) {
        while (n) {
            digits.pb(n % 10LL);
            n /= 10LL;
        }
        while ((lli)digits.size() < SIZE)
            digits.pb(0LL);
    }
};

void solve();
lli cnt0(num& n, lli i);
lli cnt1(num& n, lli i, lli d);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pow10.pb(1LL);
    for (lli _ = 1LL; _ < SIZE; ++_)
        pow10.pb(pow10.back() * 10LL);

    solve();

    return 0;
}

void solve() {
    lli a_,
        b_;
    cin >> a_ >> b_;
    ++b_;

    num a(a_),
        b(b_);
    lli neq;
    for (neq = SIZE - 1LL; a.digits[neq] == b.digits[neq]; --neq);

    lli ans = 0LL;
    for (lli i = 0LL; i < neq; ++i)
        ans += cnt0(a, i);
    for (lli i = neq; i >= 0LL; --i)
        ans += cnt1(a, i, b.digits[i]);
    cout << ans << '\n';
}

lli cnt0(num& n, lli i) {
    if (n.digits[i] == 0LL)
        return 0LL;

    lli nz;
    for (nz = SIZE - 1LL; n.digits[nz] == 0LL; --nz);
    lli sign = 1LL;

    lli res = 0LL;
    for (lli j = nz; j > i; --j, sign *= -1LL)
        res += sign * n.digits[j];
    res *= 10LL - n.digits[i];
    res *= pow10[i];

    lli i_res = 0LL;
    for (lli a = n.digits[i]; a <= 9LL; ++a)
        i_res += a;
    i_res *= pow10[i];
    i_res *= sign; sign *= -1LL;
    res += i_res;

    if (i & 1LL) {
        lli z_res = 45LL;
        z_res *= 10LL - n.digits[i];
        z_res *= pow10[i - 1LL];
        z_res *= sign; sign *= -1LL;
        res += z_res;
    }

    do {
        n.digits[i++] = 0LL;
        ++n.digits[i];
    } while (n.digits[i] == 10LL);

    return res;
}

lli cnt1(num& n, lli i, lli d) {
    if (n.digits[i] == d)
        return 0LL;

    lli nz;
    for (nz = SIZE - 1LL; n.digits[nz] == 0LL; --nz);
    lli sign = 1LL;

    lli res = 0LL;
    for (lli j = nz; j > i; --j, sign *= -1LL)
        res += sign * n.digits[j];
    res *= d - n.digits[i];
    res *= pow10[i];

    lli i_res = 0LL;
    for (lli a = n.digits[i]; a < d; ++a)
        i_res += a;
    i_res *= pow10[i];
    i_res *= sign; sign *= -1LL;
    res += i_res;

    if (i & 1LL) {
        lli z_res = 45LL;
        z_res *= d - n.digits[i];
        z_res *= pow10[i - 1LL];
        z_res *= sign; sign *= -1LL;
        res += z_res;
    }

    n.digits[i] = d;

    return res;
}
