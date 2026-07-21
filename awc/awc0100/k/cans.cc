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

// @@ !! LIM(sqrtDecomp f:intDiv f:updMaxMin)

// ---- inserted library file sqrtDecomp.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/sqrtDecomp.cc

template<typename B>
struct SRD { // square root decomposition

  int tot_size;  // total number of elements
  int bsize;  // block size
  int numb;  // number of blocks
  vector<B> _data;

  SRD() : tot_size(0), bsize(0), numb(0), _data(0) {}
  SRD(int tot_size_, int bsize_ = 0) : tot_size(tot_size_) {
    if (bsize_ > 0) bsize = bsize_;
    else            bsize = lround(sqrt(tot_size));
    numb = (tot_size + bsize - 1) / bsize;
    _data = vector<B>(numb);
  }

  pair<int, int> idx2pos(int x) { return {x / bsize, x % bsize}; }
  int pos2idx(int p, int r) { return p * bsize + r; }

  tuple<int, int, int, int, int, int> range_pos(int lo, int hi) {
    auto [lo_p, lo_r] = idx2pos(lo);
    auto [hi_p, hi_r] = idx2pos(hi);
    ll block_start = lo_r == 0 ? lo_p : lo_p + 1;
    ll block_end = hi_p;
    ll pre_start = -1, pre_end = -1, post_start = -1, post_end = -1;
    if (lo_r > 0 and hi_r > 0 and lo_p == hi_p) {
      block_start = block_end;
      post_start = lo;
      post_end = hi;
    }else {
      if (lo_r > 0) {
        pre_start = lo;
        pre_end = pos2idx(lo_p + 1, 0);
      }
      if (hi_r > 0) {
        post_start = pos2idx(hi_p, 0);
        post_end = hi;
      }
    }
    return {block_start, block_end, pre_start, pre_end, post_start, post_end};
  }

  B& data(int i) { return _data[i]; }

  int block_size(int i) {
    if (i < numb - 1) return bsize;
    else return tot_size - (numb - 1) * bsize;
  }

  void exec(int lo, int hi, auto f_edge, auto f_core) {
    auto [block_start, block_end, pre_start, pre_end, post_start, post_end] = range_pos(lo, hi);
    if (pre_start >= 0) for (int i = pre_start; i < pre_end; i++) f_edge(i, block_start - 1);
    for (int b = block_start; b < block_end; b++) f_core(b);
    if (post_start >= 0) for (int i = post_start; i < post_end; i++) f_edge(i, block_end);
  }

};


// ---- end sqrtDecomp.cc

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K, Q; cin >> N >> K >> Q;
  // @InpVec(N, A) [oUZ6Y6uG]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [oUZ6Y6uG]
  // @InpVec(N, C) [HKPeYQku]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [HKPeYQku]
  
  vector<ll> SA(N + 1);
  vector<ll> SC(N + 1);
  REP(i, 0, N) {
    SA[i + 1] = SA[i] + A[i];
    SC[i + 1] = SC[i] + C[i];
  }
  vector<ll> intFee(N - K + 1, 0LL);
  vector<ll> numPark(N - K + 1, 0LL);
  REP(i, 0, N - K + 1) {
    intFee[i] = SA[i + K] - SA[i];
    numPark[i] = SC[i + K] - SC[i];
  }

  ll big = 2e18;
  ll bsz = llround(floor(sqrt(N - K + 1)));
  ll numB = divCeil(N, bsz);
  vector<ll> base(numB, 0LL);
  vector<ll> minNumPark(numB, big);
  vector val(numB, vector(bsz + 1, big));
  REP(i, 0, N - K + 1) {
    ll p = i / bsz;
    updMin(minNumPark[p], numPark[i]);
  }
  REP(i, 0, N - K + 1) {
    ll p = i / bsz;
    REP(r, 0, numPark[i] - minNumPark[p] + 1) updMin(val[p][r], intFee[i]);
  }
  REP(_q, 0, Q) {
    ll t, x, y; cin >> t >> x >> y;
    if (t == 1) {
      ll i = x - 1;
      ll price = y;
      ll diff = price - A[i];
      A[i] = price;
      ll l = max(0LL, i - K + 1);
      ll r0 = min(N - K + 1, i + 1);
      set<ll> recalc;
      for (ll j = l; j < r0; ) {
        ll p = j / bsz;
        ll q = j % bsz;
        if (q == 0 and j + bsz <= r0) {
          base[p] += diff;
          j += bsz;
        }else {
          recalc.insert(p);
          intFee[j] += diff;
          j++;
        }
      }
      for (ll p : recalc) {
        REP(r, 0, bsz + 1) val[p][r] = big;
        ll en = min((p + 1) * bsz, N - K + 1);
        REP(j, p * bsz, en) updMin(val[p][numPark[j] - minNumPark[p]], intFee[j]);
        REPrev(r, bsz - 1, 0) updMin(val[p][r], val[p][r + 1]);
      }
    }else if (t == 2) {
      ll ans = big;
      REP(p, 0, numB) {
        updMin(ans, val[p][max(0LL, x - minNumPark[p])] + base[p]);
      }
      if (ans >= big / 2) {
        cout << "IMPOSSIBLE\n";
      }else {
        cout << ans << "\n";
      }
    }
  }


  return 0;
}

