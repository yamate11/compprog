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

// @@ !! LIM(cmpNaive)

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

// @@ !! LIM -- end mark --

int naive(istream& cin, ostream& cout) {
  ll N, M, Q; cin >> N >> M >> Q;
  // @InpVec(N, A) [XIC4rORx]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [XIC4rORx]
  // @InpVec(M, B) [EJnRn6Oo]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [EJnRn6Oo]

  REP(_q, 0, Q) {
    ll tp, i, x; cin >> tp >> i >> x; i--;
    if (tp == 1) {
      A[i] = x;
    }else if (tp == 2) {
      B[i] = x;
    }
    auto X = A;
    REP(j, 0, M) {
      X.push_back(B[j]);
      ranges::sort(X);
      swap(X[N / 2], X[N]);
      X.pop_back();
    }
    ll ans = 0;
    REP(j, 0, N) ans += X[j];
    cout << ans << endl;
  }

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N, M, Q; cin >> N >> M >> Q;
  // @InpVec(N, A) [XIC4rORx]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [XIC4rORx]
  // @InpVec(M, B) [EJnRn6Oo]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [EJnRn6Oo]

  ll H = N / 2;

  set<pll> ps;
  REP(i, 0, N) ps.emplace(A[i], i);
  REP(i, 0, M) ps.emplace(B[i], N + i);
  ll cur = 0;
  auto itLo = ps.begin();
  REP(i, 0, H) {
    cur += itLo->first;
    itLo++;
  }
  auto itHi = ps.end();
  REP(i, 0, H) {
    itHi--;
    cur += itHi->first;
  }

  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    ll i, x; cin >> i >> x; i--;
    pll oldv;
    pll newv;
    if (tp == 1) {
      oldv = pll(A[i], i);
      A[i] = x;
      newv = pll(x, i);
    }else if (tp == 2) {
      oldv = pll(B[i], N + i);
      B[i] = x;
      newv = pll(x, N + i);
    }else assert(0);
    
    if (newv == oldv) {
      // do nothing
    }else {
      ps.insert(newv);
      if (newv < *itLo) {
        cur += newv.first;
        itLo--;
        cur -= itLo->first;
      }else if (*itHi < newv) {
        cur += newv.first;
        cur -= itHi->first;
        itHi++;
      }
      auto itR = ps.find(oldv);
      assert(itR != ps.end());
      if (itLo == itR) {
        itLo++;
      }else if (itHi == itR) {
        cur -= itHi->first;
        itHi--;
        cur += itHi->first;
      }else if (oldv < *itLo) {
        cur -= oldv.first;
        cur += itLo->first;
        itLo++;
      }else if (*itHi < oldv) {
        cur -= oldv.first;
        itHi--;
        cur += itHi->first;
      }
      ps.erase(itR);
    }
    cout << cur << "\n";



  }

  return 0;
}

