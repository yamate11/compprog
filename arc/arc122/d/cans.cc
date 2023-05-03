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
  ll N; cin >> N;
  // @InpVec(2*N, A) [EoraEQlM]
  auto A = vector(2*N, ll());
  for (int i = 0; i < 2*N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [EoraEQlM]

  auto f = [&](auto rF, auto& vec, ll sz, ll acc) -> ll {
    if (sz == 0) return acc;
    ll y = LLONG_MIN;
    REP(i, 0, sz) {
      ll v = vec[i];
      ll w = vec[sz - 1];
      vec[i] = w;
      ll z = LLONG_MAX;
      REP(j, 0, sz - 1) {
        ll vv = vec[j];
        ll ww = vec[sz - 2];
        vec[j] = ww;
        ll e = rF(rF, vec, sz - 2, max(acc, v ^ vv));
        z = min(z, e);
        vec[j] = vv;
      }
      y = max(y, z);
      vec[i] = v;
    }
    return y;
  };
  cout << f(f, A, 2*N, 0) << endl;

  return 0;
}

int body(istream& cin, ostream& cout) {
  ll N; cin >> N;
  // @InpVec(2*N, A) [EoraEQlM]
  auto A = vector(2*N, ll());
  for (int i = 0; i < 2*N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [EoraEQlM]

  ll lim = 29;
  ll pat = 0;
  ll mask = 1LL << lim;
  bool single = true;
  ll score = 0;
  REPrev(k, lim, 0) {
    if (single) {
      ll cnt = 0;
      mask = 1LL << k;
      REP(i, 0, 2 * N) if ((A[i] & mask) != 0) cnt++;
      if (cnt % 2 == 0) {
      }else {
        single = false;
        pat = 1LL << k;
        score = 1LL << k;
      }
    }else {
      mask |= 1LL << k;
      ll pat1 = pat;
      ll pat2 = pat | (1LL << k);
      ll cnt1a = 0, cnt1b = 0, cnt2a = 0, cnt2b = 0;
      REP(i, 0, 2*N) {
        ll ma = A[i] & mask;
        if      (ma == (  pat1  & mask)) cnt1a++;
        else if (ma == ((~pat1) & mask)) cnt1b++;
        else if (ma == (  pat2  & mask)) cnt2a++;
        else if (ma == ((~pat2) & mask)) cnt2b++;
      }
      if (cnt1a + cnt1b == 2*N and cnt1a % 2 != 0) {
        pat = pat1;
        score |= 1LL << k;
      }else if (cnt2a + cnt2b == 2*N and cnt2a % 2 != 0) {
        pat = pat2;
        score |= 1LL << k;
      }else {
        mask ^= 1LL << k;
      }
    }
  }
  cout << score << endl;


  return 0;
}

