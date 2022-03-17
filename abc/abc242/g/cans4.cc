#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(f:perfmeas)

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double tm1 = get_time_sec();
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) {cin >> A[i]; A[i]--; }
  ll Q; cin >> Q;
  using sta = tuple<ll, ll, ll, ll>; // block, R, L, q
  vector<sta> LR;
  ll B = max(1LL, llround(1.8 * N / sqrt(Q)));
  REP(q, Q) {
    ll l, r; cin >> l >> r; l--;
    ll block = l / B;
    LR.emplace_back(block, r, l, q);
  }
  double tm2 = get_time_sec();
  sort(ALL(LR), [&](const sta& u, const sta& v) -> bool {
    const auto& [u_bl, u_r, _1, _2] = u;
    const auto& [v_bl, v_r, _3, _4] = v;
    if (u_bl != v_bl) return u_bl < v_bl;
    return u_r < v_r;
  });
  double tm3 = get_time_sec();
  vector<ll> rec(N);
  ll cnt = 0;
  ll cl = 0, cr = 0;
  ll pchk = 0;
  vector<ll> ans(Q);
  for (auto [dummy, r, l, q] : LR) {
    while (cr < r) {
      ll a = A[cr];
      rec[a]++;
      if ((rec[a] & 1) == 0) cnt++;
      cr++;
      pchk++;
    }
    while (l < cl) {
      cl--;
      ll a = A[cl];
      rec[a]++;
      if ((rec[a] & 1) == 0) cnt++;
      pchk++;
    }
    while (r < cr) {
      cr--;
      ll a = A[cr];
      rec[a]--;
      if ((rec[a] & 1) != 0) cnt--;
      pchk++;
    }
    while (cl < l) {
      ll a = A[cl];
      rec[a]--;
      if ((rec[a] & 1) != 0) cnt--;
      cl++;
      pchk++;
    }
    ans[q] = cnt;
  }
  double tm4 = get_time_sec();
  REP(q, Q) cout << ans[q] << "\n";
  double tm5 = get_time_sec();

  cerr << tm2 - tm1 << endl;
  cerr << tm3 - tm2 << endl;
  cerr << tm4 - tm3 << endl;
  cerr << tm5 - tm4 << endl;
  cerr << "pchk " << pchk << endl;
  

  return 0;
}

