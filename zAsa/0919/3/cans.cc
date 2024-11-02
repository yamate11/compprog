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

// @@ !! LIM(forall cmpNaive perm)

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    ss_out << setprecision(20);
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc

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

int naive(istream& cin, ostream& cout) {
  ll N; cin >> N;
  // @InpVec(N, A) [bVEkHgE6]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [bVEkHgE6]
  IntPerm ip(N, N);
  while (ip.get()) {
    auto check = [&]() -> bool {
      REP(i, 0, N) {
        ll p = ip.at(i);
        ll q = ip.at((i + 1) % N);
        ll r = ip.at((i + 2) % N);
        if (A[q] != (A[p] ^ A[r])) return false;
      }
      return true;
    };
    if (check()) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  // @InpVec(N, A) [bVEkHgE6]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [bVEkHgE6]
  map<ll, ll> mp;
  REP(i, 0, N) {
    mp[A[i]]++;
  }
  bool ans;
  if (N % 3 != 0) {
    ans = FORALL(i, 0, N, A[i] == 0);
  }else {
    if (ssize(mp) == 1) {
      auto it = mp.begin();
      ans = it->first == 0;
    }else if (ssize(mp) == 2) {
      auto it = mp.begin();
      ll x0 = it->first;
      ll n0 = it->second;
      it++;
      ll x1 = it->first;
      ll n1 = it->second;
      if (x0 == 0 and n0 == N / 3) ans = true;
      else if (x1 == 0 and n1 == N / 3) ans = true;
      else ans = false;
    }else if (ssize(mp) == 3) {
      auto it = mp.begin();
      ll x0 = it->first;
      ll n0 = it->second;
      it++;
      ll x1 = it->first;
      ll n1 = it->second;
      it++;
      ll x2 = it->first;
      ll n2 = it->second;
      ans = (n0 == n1 and n1 == n2 and (x0 ^ x1) == x2);
    }else {
      ans = false;
    }
  }
  cout << (ans ? "Yes\n" : "No\n");

  return 0;
}

