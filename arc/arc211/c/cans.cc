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

// @@ !! LIM(rle cmpNaive)

// ---- inserted library file rle.cc

template<class InputIt, class OutputIt>
OutputIt rle_iter(InputIt first, InputIt last, OutputIt d_first) {
  InputIt itA = first;
  OutputIt oit = d_first;
  while (itA != last) {
    InputIt itB = next(itA);
    for (; itB != last and *itA == *itB; itB++);
    *oit = make_pair(*itA, itB - itA);
    itA = itB;
    oit++;
  }
  return oit;
}

template<class V>
auto rle(V vec) {
  vector<pair<typename V::value_type, ll>> ret;
  rle_iter(vec.begin(), vec.end(), back_inserter(ret));
  return ret;
}

// ---- end rle.cc

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

  ll N; cin >> N;
  string S; cin >> S;
  // @InpVec(N, R) [CXz8Xu6n]
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; R[i] = v; }
  // @End [CXz8Xu6n]
  
  auto f = [&](auto rF, string s) -> ll {
    ll ret = 0;
    REP(i, 0, N) REP(j, i + 2, N) {
      if (s[i] == '#' or s[j] == '#') continue;
      string t = s.substr(i, j - i + 1);
      auto vv = rle(t);
      if (ssize(vv) != 3) continue;
      string u = s;
      REP(k, i, j + 1) u[k] = '.';
      ll cur = rF(rF, u) + R[i] + R[j];
      ret = max(ret, cur);
    }
    return ret;
  };

  map<ll, ll> mp;
  REP(i, 0, N) REP(j, i + 2, N) {
    if (S[i] == '#' or S[j] == '#') continue;
    string t = S.substr(i, j - i + 1);
    auto vv = rle(t);
    if (ssize(vv) != 3) continue;
    string u = S;
    REP(k, i, j + 1) u[k] = '.';
    auto score = f(f, u) + R[i] + R[j];
    mp[score]++;
  }
  if (mp.empty()) {
    cout << 0 << endl;
  }else {
    auto it = mp.end();
    it--;
    cout << it->second << endl;
  }

  return 0;
}
int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  string S; cin >> S;
  // @InpVec(N, R) [CXz8Xu6n]
  auto R = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; R[i] = v; }
  // @End [CXz8Xu6n]

  auto vec = rle(S);
  ll szrle = ssize(vec);
  vector W(szrle, 0LL);
  vector U(szrle, 0LL);
  {
    ll z = 0;
    REP(i, 0, szrle) {
      ll zz = z + vec[i].second;
      ll w = 0;
      REP(j, z, zz) w = max(w, R[j]);
      ll u = 0;
      REP(j, z, z + vec[i].second) if (R[j] == w) u++;
      W[i] = w;
      U[i] = u;
      z = zz;
    }
  }

  ll i = 0;
  if (vec[0].first == '#') {
    i += 1;
  }
  ll biggest = 0;
  REP(ii, i, szrle) {
    if (ii == szrle - 1 and vec[ii].first == '#') break;
    biggest = max(biggest, W[ii]);
  }

  ll ans = 0;
  while (i + 2 < szrle) {
    if (W[i + 1] == biggest or W[i] == biggest or W[i + 2] == biggest) ans += U[i] * U[i + 2];
    i += 2;
  }
  cout << ans << endl;
  return 0;
}


