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

// @@ !! LIM(perm)

// ---- inserted library file perm.cc

template <bool dup>
struct IntPermBase {
  int n;
  int r;
  vector<int> vec;
  bool started;

  bool start_check() {
    if constexpr (dup) { if (not ((1 <= n and 0 <= r) or (n == 0 and r == 0))) return false; }
    else { if (not (0 <= n and 0 <= r and r <= n)) return false; }
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  IntPermBase(int n_, int r_) : n(n_), r(r_), started(false) {}

  int at(int i) const { return vec[i]; }

  const vector<int>& vec_view() const { return vec; }
};

struct IntPerm : IntPermBase<false> {
  vector<vector<int>> cands;
  vector<int> cidx;

  bool start_check() {
    if (not IntPermBase<false>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    cands.resize(r);
    cidx.resize(r);
    for (int i = 0; i < r; i++) {
      for (int j = n - 1; j >= i; j--) cands[i].push_back(j);
      cidx[i] = n - i - 1;
    }
    return true;
  }

  bool finish() {
    cands.resize(0);
    cidx.resize(0);
    return IntPermBase<false>::finish();
  }

  IntPerm(int n_, int r_) : IntPermBase<false>(n_, r_) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and cidx[i] == 0; i--);
    if (i < 0) return finish();
    vec[i] = cands[i][--cidx[i]];
    for (int j = i + 1; j < r; j++) {
      if (j == i + 1) {
        cands[j].resize(0);
        for (int k = 0; k < (int)cands[i].size(); k++) {
          if (k == cidx[i]) continue;
          cands[j].push_back(cands[i][k]);
        }
      }else {
        cands[j] = cands[j - 1];
        cands[j].pop_back();
      }
      cidx[j] = n - j - 1;
      vec[j] = cands[j][cidx[j]];
    }
    return true;
  }
};

struct IntComb : IntPermBase<false> {
  bool start_check() {
    if (not IntPermBase<false>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    return true;
  }

  IntComb(int n_, int r_) : IntPermBase<false>(n_, r_) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - r + i; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[j - 1] + 1;
    return true;
  }
};

struct IntDupPerm : IntPermBase<true> {
  IntDupPerm(int n_, int r_) : IntPermBase<true>(n_, r_) {}

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < n) return true;
    return finish();
  }
};

struct IntDupComb : IntPermBase<true> {
  IntDupComb(int n_, int r_) : IntPermBase<true>(n_, r_) {}

  bool get() {
    if (not started) return start_check();
    int i = r - 1;
    for (; i >= 0 and vec[i] == n - 1; i--);
    if (i < 0) return finish();
    vec[i]++;
    for (int j = i + 1; j < r; j++) vec[j] = vec[i];
    return true;
  }
};

template<typename INT>
struct IntDirProd {
  vector<INT> lim;
  int r;
  vector<INT> vec;
  bool started;

  IntDirProd(const vector<INT>& lim_) : lim(lim_), r(lim.size()), started(false) {}

  int at(int i) const { return vec[i]; }

  const vector<INT>& vec_view() const { return vec; }

  bool start_check() {
    for (int i = 0; i < r; i++) if (lim[i] == 0) return false;
    started = true;
    vec.resize(r, 0);
    return true;
  }

  bool finish() {
    vec.resize(0);
    started = false;
    return false;
  }

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < lim[i]) return true;
    return finish();
  }

};

// ---- end perm.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string X; cin >> X;
  // @InpVec(N, S, type=string) [EO3CFGYR]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [EO3CFGYR]

  auto better = [&](ll n1, ll c1, ll i1, ll n2, ll c2, ll i2) -> bool {
    if (n1 != n2) return n1 > n2;
    if (c1 != c2) return c1 < c2;
    if (i1 != i2) return i1 < i2;
    return false;
  };

  vector<ll> NI(N, 0LL);
  vector<ll> CI(N, 26LL);
  REP(i, 0, N) {
    IntComb icX(5, 3);
    IntComb icS(4, 2);
    while (icX.get()) {
      while (icS.get()) {
        vector<ll> hand(26, 0LL);
        REP(j, 0, 3) hand[X[icX.at(j)] - 'A']++;
        REP(j, 0, 2) hand[S[i][icS.at(j)] - 'A']++;

        ll c0 = -1, n0 = 0;
        REP(c, 0, 26) {
          if (hand[c] > n0) {
            n0 = hand[c];
            c0 = c;
          }
        }
        if (better(n0, c0, i, NI[i], CI[i], i)) {
          NI[i] = n0;
          CI[i] = c0;
        }
      }
    }
  }
  ll ans = 0;
  REP(i, 1, N) {
    if (better(NI[i], CI[i], i, NI[ans], CI[ans], ans)) ans = i;
  }
  cout << ans + 1 << endl;

  return 0;
}
