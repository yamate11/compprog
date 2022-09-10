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

// @@ !! LIM(cycledetect cmpNaive)

// ---- inserted library file cycledetect.cc

pair<vector<int>, int> func_cycle_detect(int n, int init, auto f) {
  vector<int> ret;
  vector<int> record(n, -1);
  int a = init;
  for (int i = 0; true; i++) {
    if (record[a] >= 0) return {move(ret), record[a]};
    ret.push_back(a);
    record[a] = i;
    a = f(a);
  }
}

template<bool directed>
pair<vector<int>, int> graph_cycle_detect(int n, int init, const auto& fwd) {
  struct myexc : exception {};
  vector<int> ret;
  vector<int> record(n, -1);
  vector<bool> visited(n);
  int ret_idx = -1;
  auto dfs = [&](auto rF, int nd, int idx, int pt) -> void {
    if (record[nd] >= 0) {
      ret_idx = record[nd];
      throw myexc();
    }
    if (visited[nd]) return;
    visited[nd] = true;
    ret.push_back(nd);
    record[nd] = idx;
    for (int cld : fwd[nd]) {
      if constexpr (not directed) {
        if (cld == pt) continue;
      }
      rF(rF, cld, idx + 1, nd);
    }
    record[nd] = -1;
    ret.pop_back();
  };
  try {
    dfs(dfs, init, 0, -1);
    return {vector<int>(), -1};
  }catch (myexc& e) {
    return {move(ret), ret_idx};
  }
}

pair<vector<int>, int> directed_cycle_detect(int n, int init, const auto& fwd) {
  return graph_cycle_detect<true>(n, init, fwd);
}
pair<vector<int>, int> undirected_cycle_detect(int n, int init, const auto& nbr) {
  return graph_cycle_detect<false>(n, init, nbr);
}

// ---- end cycledetect.cc

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

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N, K; cin >> N >> K;
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }

  ll s = 0;
  REP(i, 0, K) {
    s += A[s % N];
  }
  cout << s << endl;

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, K; cin >> N >> K;
  //@InpVec(N, A) [jgQF1zbi]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [jgQF1zbi]
  auto f = [&](ll i) -> ll {
    return (i + A[i]) % N;
  };
  auto [vec, idx] = func_cycle_detect(N, 0, f);
  ll cl = SIZE(vec) - idx;
  ll z = (K - idx) % cl;
  ll nl = (K - idx) / cl;
  if (K <= SIZE(vec)) {
    ll s = 0;
    REP(i, 0, K) s += A[s % N];
    cout << s << endl;
    return 0;
  }
  ll s = 0;
  REP(i, 0, idx + z) s += A[s % N];
  ll s0 = s;
  REP(i, 0, cl) s += A[s % N];
  ll s1 = s;
  cout << s0 + (s1 - s0) * nl << endl;

  return 0;
}

