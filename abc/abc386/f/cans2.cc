#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K; cin >> K;
  string S, T; cin >> S >> T;
  ll ns = ssize(S);
  ll nt = ssize(T);

  auto mktbl = [&](string U) {
    ll m = ssize(U);
    vector ret(m, vector<ll>());
    vector<ll> tbl(26, -1LL);
    REPrev(i, m - 1, 0) {
      ll d = U[i] - 'a';
      ret[i] = tbl;
      tbl[d] = i;
    }
    return ret;
  };

  auto tblS = mktbl(S);
  auto tblT = mktbl(T);

  auto f = [&](auto rF, ll pen, ll i0, ll j0) -> bool {
    ll lendiff = abs((ns - i0) - (nt - j0));
    if (pen + lendiff > K) return false;
    if (i0 == ns and j0 == nt) return true;
    if (i0 == ns) return rF(rF, pen + nt - j0, ns, nt);
    if (j0 == nt) return rF(rF, pen + ns - i0, ns, nt);
    if (S[i0] == T[j0]) return rF(rF, pen, i0 + 1, j0 + 1);
    if (rF(rF, pen + 1, i0 + 1, j0 + 1)) return true;
    ll j = tblT[j0][S[i0] - 'a'];
    if (j >= 0) {
      bool b = rF(rF, pen + j - j0, i0 + 1, j + 1);
      if (b) return true;
    }
    ll i = tblS[i0][T[j0] - 'a'];
    if (i >= 0) {
      bool b = rF(rF, pen + i - i0, i + 1, j0 + 1);
      if (b) return true;
    }
    return false;
  };

  bool b = f(f, 0, 0, 0);
  cout << (b ? "Yes\n" : "No\n");

  return 0;
}

