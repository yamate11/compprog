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
// published at https://github.com/yamate11/compprog-clib/blob/master/perm.cc

template <bool dup, typename T>
struct IntPermBase {
  int n;
  int r;
  vector<int> vec;
  bool started;
  vector<T> mapping;

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

  IntPermBase(int n_, int r_) : n(n_), r(r_), started(false) {
    if (n >= 0) {
      mapping = vector<T>(n);
      for (int i = 0; i < n; i++) {
        if constexpr (is_integral<T>::value) mapping[i] = (T)i;
        else mapping[i] = T();
      }
    }
  }
  IntPermBase(int n_, int r_, vector<T> mp) : n(n_), r(r_), started(false), mapping(move(mp)) {
    if (ssize(mapping) != n) throw runtime_error("IntPermBase: incorrect mapping length");
  }

  T at(int i) const { return mapping[vec[i]]; }

  T operator[](int i) const { return at(i); }

  void set_mapping(auto f) {
    for (int i = 0; i < n; i++) mapping[i] = f(i);
  }

  vector<T> vec_view() const {
    vector<T> res;
    for (int i = 0; i < r; i++) res.push_back(mapping[vec[i]]);
    return res;
  }
};

template<typename T = int>
struct IntPerm : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started;

  vector<vector<int>> cands;
  vector<int> cidx;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
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
    return IntPermBase<false, T>::finish();
  }

  IntPerm(int n_, int r_) : IntPermBase<false, T>(n_, r_) {}
  IntPerm(int n_, int r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

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

template<typename T = int>
struct IntComb : IntPermBase<false, T> {
  using Base = IntPermBase<false, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish;

  bool start_check() {
    if (not IntPermBase<false, T>::start_check()) return false;
    iota(vec.begin(), vec.end(), 0);
    return true;
  }

  IntComb(int n_, int r_) : IntPermBase<false, T>(n_, r_) {}
  IntComb(int n_, int r_, vector<T> mp) : IntPermBase<false, T>(n_, r_, mp) {}

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

template<typename T = int>
struct IntDupPerm : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupPerm(int n_, int r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupPerm(int n_, int r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

  bool get() {
    if (not started) return start_check();
    for (int i = r - 1; i >= 0; vec[i--] = 0) if (++vec[i] < n) return true;
    return finish();
  }
};

template<typename T = int>
struct IntDupComb : IntPermBase<true, T> {
  using Base = IntPermBase<true, T>;
  using Base::vec, Base::r, Base::n, Base::started, Base::finish, Base::start_check;

  IntDupComb(int n_, int r_) : IntPermBase<true, T>(n_, r_) {}
  IntDupComb(int n_, int r_, vector<T> mp) : IntPermBase<true, T>(n_, r_, mp) {}

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

struct IDCBoxBall {
  int box;
  int ball;
  IntDupComb<> idc;
  vector<int> numBalls;
  IDCBoxBall(int box_, int ball_) : box(box_), ball(ball_), idc(box, ball) {}
  bool get() {
    bool b = idc.get();
    if (not b) return false;
    numBalls = vector<int>(box);
    for (int i = 0; i < ball; i++) numBalls[idc.at(i)]++;
    return true;
  }
  int at(int i) const { return numBalls[i]; }
  int operator[](int i) const { return at(i); }
  vector<int> vec_view() const { return numBalls; }
};


template<typename INT>
struct IntDirProd {
  vector<INT> lim;
  int r;
  vector<INT> vec;
  bool started;

  IntDirProd(const vector<INT>& lim_) : lim(lim_), r(lim.size()), started(false) {}

  int at(int i) const { return vec[i]; }
  int operator[](int i) const { return at(i); }

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

template<typename INT>
struct IntPartition {
  INT n;
  vector<INT> vec;
  bool started = false;
  IntPartition(INT n_) : n(n_) {}
  
  bool get() {
    if (not started) {
      started = true;
      vec = vector<INT>(n, 1);
      return true;
    }else if (ssize(vec) == 1) {
      started = false;
      return false;
    }else {
      ll b = vec.back(); vec.pop_back();
      ll a = vec.back(); vec.pop_back();
      ll c = a + b;
      ll a1 = a + 1;
      while (c - a1 >= a1) {
        vec.push_back(a1);
        c -= a1;
      }
      vec.push_back(c);
      return true;
    }
  }

  INT at(int i) const { return vec[i]; }
  const vector<INT>& vec_view() const { return vec; }
};

// ---- end perm.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;

  if (N == 1) {
    cout << 1 << endl;
    cout << "ab" << endl;
    return 0;
  }

  auto f = [&](const auto& nbr) -> vector<string> {
    vector tbl(N, vector<string>());
    auto dfs = [&](auto rF, ll nd, ll pt) -> void {
      if (not tbl[nd].empty()) return;
      if (nd > 0 and ssize(nbr[nd]) == 1) {
        tbl[nd] = vector<string>{"ab"};
        return;
      }
      vector<ll> cs;
      for (ll peer : nbr[nd]) if (peer != pt) {
          cs.push_back(peer);
          rF(rF, peer, nd);
        }
      ll numC = ssize(cs);
      IntPerm ip(numC, numC);
      while (ip.get()) {
        vector vj(numC, 0LL);
        REP(i, 0, numC) vj[i] = ssize(tbl[cs[ip[i]]]);
        IntDirProd idp(vj);
        while (idp.get()) {
          string t = "a";
          REP(i, 0, numC) t += tbl[cs[ip[i]]][idp[i]];
          t += "b";
          tbl[nd].push_back(move(t));
        }
      }
      ranges::sort(tbl[nd]);
      tbl[nd].erase(unique(ALL(tbl[nd])), tbl[nd].end());
    };
    dfs(dfs, 0, -1);
    return tbl[0];
  };


  // @InpNbrList(N, N - 1, nbrA, dec=1) [3S0b9D6Y]
  auto nbrA = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbrA[u].emplace_back(v);
    nbrA[v].emplace_back(u);
  }
  // @End [3S0b9D6Y]
  // @InpNbrList(N, N - 1, nbrB, dec=1) [d8IH2kGC]
  auto nbrB = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbrB[u].emplace_back(v);
    nbrB[v].emplace_back(u);
  }
  // @End [d8IH2kGC]
  
  auto ssA = f(nbrA);
  auto ssB = f(nbrB);
  vector<string> ans;
  {
    ll i = 0, j = 0;
    while (i < ssize(ssA) and j < ssize(ssB)) {
      if (ssA[i] == ssB[j]) {
        ans.push_back(ssA[i]);
        i++;
        j++;
      }else if (ssA[i] < ssB[j]) i++;
      else j++;
    }
  }
  cout << ssize(ans) << "\n";
  REPOUT(i, 0, ssize(ans), ans[i], "\n");

  return 0;
}

