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



/*
ll _hil_ord(ll acc, ll x, ll y, ll k, ll in, ll dir) {
  if (k < 0) return acc;
  ll a = x >> k & 1;
  ll b = y >> k & 1;
  ll t = a << 1 | b;
  ll tt = t ^ in;
  if (tt == 0) {
    return _hil_ord(acc | 0LL << (2 * k), x, y, k - 1, (t & dir) ? 3 : 0, dir ^ 3);  
  }else if (tt == dir) {
    return _hil_ord(acc | 1LL << (2 * k), x, y, k - 1, (t & dir) ? 0 : 3, dir);  
  }else if (tt == 3) {
    return _hil_ord(acc | 2LL << (2 * k), x, y, k - 1, (t & dir) ? 0 : 3, dir);  
  }else {
    return _hil_ord(acc | 3LL << (2 * k), x, y, k - 1, (t & dir) ? 0 : 3, dir ^ 3);  
  }
}

ll hilbertOrder(ll x, ll y, ll k) { return _hil_ord(0, x, y, k - 1, 0, 1); }
*/

ll hilbertOrder(ll x, ll y, ll k) { // 0 <= x,y < 2^k
  ll acc = 0;
  ll in = 0;
  ll dir = 1;
  while (--k >= 0) {
    ll t = (x >> k & 1) << 1 | (y >> k & 1);
    ll tt = t ^ in;
    ll c, pat1, pat2, mask;
    if (tt == 0)        { c = 0; pat1 = 3; pat2 = 0; mask = 3; }
    else if (tt == dir) { c = 1; pat1 = 0; pat2 = 3; mask = 0; }
    else if (tt == 3)   { c = 2; pat1 = 0; pat2 = 3; mask = 0; }
    else                { c = 3; pat1 = 0; pat2 = 3; mask = 3; }
    acc |= c << (2 * k);
    in = (t & dir) ? pat1 : pat2;
    dir ^= mask;
  }
  return acc;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  double tm1 = get_time_sec();
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) {cin >> A[i]; A[i]--; }
  ll Q; cin >> Q;
  struct sta {
    ll ord;
    ll l;
    ll r;
    ll q;
    sta(ll ord_, ll l_, ll r_, ll q_) : ord(ord_), l(l_), r(r_), q(q_) {}
  };
  // using sta = tuple<ll, ll, ll, ll>; // hilbert-curve-order, L, R, q
  vector<sta> LR;
  ll K = 64 - __builtin_clzll(N);
  REP(q, Q) {
    ll l, r; cin >> l >> r; l--;
    LR.emplace_back(hilbertOrder(l, r, K), l, r, q);
  }
  double tm2 = get_time_sec();
  sort(ALL(LR), [](const sta& u1, const sta& u2) -> bool { return u1.ord < u2.ord; });
  double tm3 = get_time_sec();
  vector<ll> rec(N);
  ll cnt = 0;
  ll cl = 0, cr = 0;
  ll pchk = 0;
  vector<ll> ans(Q);
  for (auto [dummy, l, r, q] : LR) {
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
  cerr << "allt " << tm5 - tm1 << endl;
  cerr << "pchk " << pchk << endl;

  return 0;
}

