#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

// @DefStruct(ta, (t, a), ord=((a, True))) [IMpSIhn6]
struct ta_t {
  ll t;
  ll a;
  ta_t() {}
  ta_t(ll t_, ll a_) : t(t_), a(a_) {}
  friend istream& operator>>(istream& istr, ta_t& t) {
    istr >> t.t >> t.a;
    return istr;
  }
  bool operator<(const ta_t& o) const {
    if (a > o.a) return true;
    return false;
  }
};
// @End [IMpSIhn6]

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  const ll lim = 1e5;
  ll N, X; cin >> N >> X;
  // @InpVec(N, T) [PbdSa91F]
  auto T = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; T[i] = v; }
  // @End [PbdSa91F]
  // @InpVec(N, A) [fNoybp7F]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [fNoybp7F]
  auto ta = vector<ta_t>(N);
  REP(i, 0, N) ta[i] = ta_t(T[i], A[i]);
  sort(ALL(ta));

  ll val = 0;
  ll cnt = 0;
  set<ll> ss;
  REP(i, -1, lim + 2) ss.insert(ss.end(), i);
  for (auto [t, a] : ta) {
    t--;
    auto it = ss.lower_bound(t);
    if (t < *it) it--;
    if (*it == -1) continue;
    ss.erase(it);
    val += a;
    cnt++;
    if (val >= X) break;
  }
  if (val < X) {
    cout << -1 << endl;
    return 0;
  }
  cout << cnt << endl;


  return 0;
}

