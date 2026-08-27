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

  ll N; cin >> N;
  auto f = [&](const string& s) -> vector<ll> {
    vector<ll> ret;
    REP(i, 0, 2 * N) {
      if (s[i] == '0') ret.push_back(i);
    }
    assert(ssize(ret) == N);
    REP(i, 0, N) ret[i] -= i;
    return ret;
  };
  auto g = [&](ll a, ll b, ll c) -> ll {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    return b;
  };

  vector<string> S(3);
  REP(i, 0, 3) cin >> S[i];
  vector<vector<ll>> V(3);
  REP(i, 0, 3) V[i] = f(S[i]);
  vector<ll> W(N);
  ll d = 0;
  REP(i, 0, N) {
    ll x = g(V[0][i], V[1][i], V[2][i]);
    W[i] = i + x;
    d += abs(x - V[0][i]) + abs(x - V[1][i]) + abs(x - V[2][i]);
  }
  string ans(2*N, '1');
  REP(i, 0, N) ans[W[i]] = '0';
  cout << d << "\n";
  cout << ans << "\n";
  


  return 0;
}

