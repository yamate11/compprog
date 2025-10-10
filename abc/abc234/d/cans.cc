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

// @@ !! LIM(wavelet)

// ---- inserted library file wavelet.cc

struct BitVector {
  ll N;
  ll vsize;
  vector<int> vs;
  vector<u64> vb;
  bool built;
  BitVector() = default;
  BitVector(ll N_) : N(N_), vsize((N + 63) / 64), vs(vsize + 1), vb(vsize), built(false) {}
  void set(bool val, int k) {
    if (built) throw runtime_error("already built.");
    if (val) vb[k >> 6] |=   1ULL << (k & 63);
    else     vb[k >> 6] &= ~(1ULL << (k & 63));
  }
  bool at(ll k) { return static_cast<bool>(vb[k >> 6] >> (k & 63) & 1); }
  void build() {
    if (not built) {
      for (ll i = 0; i < vsize; i++) vs[i + 1] = vs[i] + popcount(vb[i]);
      built = true;
    }
  }
  ll rank(bool val, ll k) {
    if (not built) build();
    ll cnt1 = vs[k >> 6] + popcount(vb[k >> 6] & ((1ULL << (k & 63)) - 1));
    if (val) return cnt1;
    else     return k - cnt1;
  }

  // for debugging
  vector<bool> vec_view() {
    vector<bool> vec(N);
    for (ll i = 0; i < N; i++) vec[i] = at(i);
    return vec;
  }

};

template<typename INT=ll>
struct WaveletMatrix {
  ll N;
  ll ht;
  vector<BitVector> vbv;
  vector<int> mid;

  pair<bool, INT> _h_rest(ll h, INT t) { return {t >> h & 1, t & ((static_cast<INT>(1) << h) - 1)}; }

  WaveletMatrix() = default;
  WaveletMatrix(const auto& vec, ll amax) : N(vec.size()), ht(bit_width((u64)amax)), vbv(ht, BitVector(N)), mid(ht) {
    vector tmpA{vec, vector<INT>(N)};
    vector tmpB(2, vector<INT>(N));
    vector<ll> a{N, 0};
    vector<ll> b{0, 0};
    for (ll h = ht - 1; h >= 0; h--) {
      for (int e = 0; e < 2; e++) {
        for (ll i = 0; i < a[e]; i++) {
          auto [x, y] = _h_rest(h, tmpA[e][i]);
          vbv[h].set(x, e == 0 ? i : a[0] + i);
          tmpB[x][b[x]++] = y;
        }
      }
      mid[h] = b[0];
      swap(tmpA, tmpB);
      a = b;
      b[0] = b[1] = 0;
    }
  }
  
  pair<ll, ll> _next_range(bool x, ll l, ll r, ll h) {
    return {x * mid[h] + vbv[h].rank(x, l), x * mid[h] + vbv[h].rank(x, r)};
  }

  // vec[p]
  INT access(ll p) {
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      bool x = vbv[h].at(p);
      if (x == 1) ret |= INT(1) << h;
      if (x == 0) p =          vbv[h].rank(0, p);
      else        p = mid[h] + vbv[h].rank(1, p);
    }
    return ret;
  }

  // #{ i < r : vec[i] == t }
  ll rank(INT t, ll r) {
    ll l = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = t >> h & 1;
      tie (l, r) = _next_range(x, l, r, h);
    }
    return r - l;
  }

  // k-th smallest value in vec[l, r)   (0-indexed)
  INT kth_smallest(ll k, ll l, ll r) {
    INT ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll num0 = vbv[h].rank(0, r) - vbv[h].rank(0, l);
      bool x = k >= num0;
      if (x) {
        k -= num0;
        ret |= INT(1) << h;
      }
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // #{ i \in [l, r) : vec[i] < hi }
  ll range_freq(INT hi, ll l, ll r) {
    ll ret = 0;
    for (ll h = ht - 1; h >= 0; h--) {
      ll x = hi >> h & 1;
      if (x == 1) ret += vbv[h].rank(0, r) - vbv[h].rank(0, l);
      tie(l, r) = _next_range(x, l, r, h);
    }
    return ret;
  }

  // #{i \in [l, r) : lo <= vec[i] < hi }
  ll range_freq(INT lo, INT hi, ll l, ll r) { return range_freq(hi, l, r) - range_freq(lo, l, r); }


};



// ---- end wavelet.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpVec(N, P) [DnVmkeo4]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [DnVmkeo4]

  WaveletMatrix wm(P, (ll)5e5 + 10);
  vector<ll> ans;
  REP(i, K, N + 1) ans.push_back(wm.kth_smallest(i - 1 - (K - 1), 0, i));
  REPOUT(i, 0, ssize(ans), ans[i], "\n");

  return 0;
}

