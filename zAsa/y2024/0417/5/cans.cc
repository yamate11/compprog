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

// @@ !! LIM(cmpNaive perm)

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
  ll N, K; cin >> N >> K;
  // @InpVec(N, V) [Da9cHSo6]
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; V[i] = v; }
  // @End [Da9cHSo6]

  IntDupPerm dip(4, K);
  ll ans = 0;
  while (dip.get()) {
    deque<ll> deq;
    REP(i, 0, N) deq.push_back(V[i]);
    multiset<ll> ss;
    REP(i, 0, K) {
      if (dip.at(i) == 0) {
        if (not deq.empty()) {
          ll x = deq.front(); deq.pop_front();
          ss.insert(x);
        }
      }else if (dip.at(i) == 1) {
        if (not deq.empty()) {
          ll x = deq.back(); deq.pop_back();
          ss.insert(x);
        }
      }else if (dip.at(i) == 2) {
        if (not ss.empty()) {
          auto it = ss.begin();
          ll x = *it;
          ss.erase(it);
          deq.push_front(x);
        }
      }else if (dip.at(i) == 3) {
        if (not ss.empty()) {
          auto it = ss.begin();
          ll x = *it;
          ss.erase(it);
          deq.push_back(x);
        }
      }else assert(0);
    }
    ll s = 0;
    for (ll x : ss) s += x;
    ans = max(ans, s);
  }
  cout << ans << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, K; cin >> N >> K;
  // @InpVec(N, V) [Da9cHSo6]
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; V[i] = v; }
  // @End [Da9cHSo6]

  ll ans = 0;
  REP(a, 0, min(K + 1, N + 1)) {
    REP(x, 0, a + 1) {
      ll y = a - x;
      vector<ll> tmp;
      REP(i, 0, x) tmp.push_back(V[i]);
      REP(i, 0, y) tmp.push_back(V[N - 1 -i]);
      sort(ALL(tmp));
      ll s = 0;
      REP(i, 0, a) {
        if (i < K - a and tmp[i] < 0) continue;
        s += tmp[i];
      }
      ans = max(ans, s);
    }
  }
  cout << ans << endl;

  return 0;
}

