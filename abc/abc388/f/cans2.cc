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
  ll N, M, A, B; cin >> N >> M >> A >> B;
  // @InpMVec(M, ((L, dec=1), (R, dec=1))) [s4dUqcr1]
  auto L = vector(M, ll());
  auto R = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; v2 -= 1; R[i] = v2;
  }
  // @End [s4dUqcr1]

  vector<ll> P(N, 0LL);
  REP(i, 0, M) REP(x, L[i], R[i] + 1) P[x] = -1;
  P[0] = 1;
  REP(i, 0, N) {
    if (P[i] == 1) {
      REP(j, A, B + 1) if (i + j < N and P[i + j] == 0) P[i + j] = 1;
    }
  }
  cout << (P[N - 1] == 1 ? "Yes\n" : "No\n");

  return 0;
}

int body(istream& cin, ostream& cout) {

  auto solve = [&]() -> bool {
    ll N, M, A, B; cin >> N >> M >> A >> B;
    // @InpMVec(M, ((L, dec=1), (R, dec=0))) [SMLdQHlE]
    auto L = vector(M, ll());
    auto R = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; L[i] = v1;
      ll v2; cin >> v2; v2 -= 0; R[i] = v2;
    }
    // @End [SMLdQHlE]

    if (A == B) {
      if ((N - 1) % A != 0) return false;
      REP(k, 0, M) {
        ll x = L[k] % A;
        if (x == 0) return false;
        if (L[k] + A - x < R[k]) return false;
      }
      return true;
    }


    ll lim = (A + 1) * (B + 1) + 1;
    vector LL(M + 1, 0LL);
    vector RR(M + 1, 0LL);
    LL[0] = 0;
    RR[M] = N;
    REP(i, 0, M) {
      RR[i] = L[i];
      LL[i + 1] = R[i];
    }
    auto is_short = [&](ll i) -> bool { return RR[i] - LL[i] < lim; };
    vector vec(M + 1, vector<bool>());
    REP(i, 0, M + 1) {
      if (is_short(i)) vec[i] = vector<bool>(RR[i] - LL[i], false);
      else             vec[i] = vector<bool>(1, false);
    }
    vec[0][0] = true;
    REP(k, 0, M + 1) {
      if (is_short(k)) {
        REP(i, 0, ssize(vec[k])) {
          if (vec[k][i]) {
            REP(j, A, B + 1) {
              if (i + j < ssize(vec[k])) vec[k][i + j] = true;
              else {
                ll apos = LL[k] + i + j;
                REP(kk, k + 1, M + 1) {
                  if (apos < LL[kk]) break;
                  if (apos < RR[kk]) {
                    if (is_short(kk)) vec[kk][apos - LL[kk]] = true;
                    else           vec[kk][0] = true;
                    break;
                  }
                }
              }
            }
          }
        }
      }else {
        if (not vec[k][0]) break;
        REP(i, RR[k] - B, RR[k]) {
          REP(j, A, B + 1) {
            ll apos = i + j;
            REP(kk, k + 1, M + 1) {
              if (apos < LL[kk]) break;
              if (apos < RR[kk]) {
                if (is_short(kk)) vec[kk][apos - LL[kk]] = true;
                else           vec[kk][0] = true;
                break;
              }
            }
          }
        }
      }
    }
    return vec[M].back();
  };

  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

