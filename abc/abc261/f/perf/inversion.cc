#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#include <atcoder/segtree>
#include <atcoder/fenwicktree>
using namespace atcoder;

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

using pll = pair<ll, ll>;
using myset_t = tree<
  // pll,
  ll,
  null_type,
  // greater<pll>,
  greater<ll>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;


ll f_pbds(ll n, auto& vec) {
  ll ret = 0;
  myset_t myset;
  REP(i, n) {
    // pll p(vec[i], i);
    ll p = vec[i] * n + i;
    ret += myset.order_of_key(p);
    myset.insert(p);
  }
  return ret;
}

ll op(ll x, ll y) { return x + y; };
ll e() { return 0LL; };

ll f_segtree(ll n, auto& vec) {
  segtree<ll, op, e> seg(n);
  ll ret = 0;
  REP(i, n) {
    ret += seg.prod(vec[i] + 1, n);
    seg.set(vec[i], seg.get(vec[i]) + 1);
  }
  return ret;
}

ll f_fenwick(ll n, auto& vec) {
  fenwick_tree<ll> fw(n);
  ll ret = 0;
  REP(i, n) {
    ret += fw.sum(vec[i] + 1, n);
    fw.add(vec[i], 1);
  }
  return ret;
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];

  double t2 = get_time_sec();
  ll a2 = f_segtree(N, A);
  double t3 = get_time_sec();
  ll a3 = f_fenwick(N, A);
  double t4 = get_time_sec();
  ll a1 = f_pbds(N, A);
  double t5 = get_time_sec();

  cout << "Segment Tree " << t3 - t2 << endl;
  cout << "Fenwick Tree " << t4 - t3 << endl;
  cout << "PBDS         " << t5 - t4 << endl;

  assert(a1 == a2);
  assert(a1 == a3);

  return 0;
}

