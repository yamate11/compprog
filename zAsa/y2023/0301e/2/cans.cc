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

// @@ !! LIM(input debug f:updMaxMin cmpNaive)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted function f:<< from util.cc
template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
}

// ---- end f:<<

// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

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
  ll H, W; cin >> H >> W;
  // @InpGrid(H, W, B) [K06UFXfE]
  auto B = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; B[i][j] = v; }
  // @End [K06UFXfE]

  vector S(H + 1, vector(W + 1, 0LL));
  REP(i, 1, H + 1) REP(j, 1, W + 1) S[i][j] = B[i - 1][j - 1];
  REP(i, 1, H + 1) REP(j, 1, W + 1) S[i][j] += S[i][j - 1];
  REP(j, 1, W + 1) REP(i, 1, H + 1) S[i][j] += S[i - 1][j];

  auto area = [&](ll i0, ll i1, ll j0, ll j1) -> ll {
    return S[i0][j0] + S[i1][j1] - (S[i0][j1] + S[i1][j0]);
  };

  ll ans = LLONG_MIN;
  REP(i0, 0, H) REP(i1, i0 + 1, H + 1) REP(j0, 0, W) REP(j1, j0 + 1, W + 1) {
    ll s = area(i0, i1, j0, j1);
    REP(k0, 0, i0) REP(k1, k0 + 1, i0 + 1) REP(l0, 0, W) REP(l1, l0 + 1, W + 1) {
      ll t = area(k0, k1, l0, l1);
      updMax(ans, s + t);
    }
    REP(k0, i1, H) REP(k1, k0 + 1, H + 1) REP(l0, 0, W) REP(l1, l0 + 1, W + 1) {
      ll t = area(k0, k1, l0, l1);
      updMax(ans, s + t);
    }
    REP(k0, 0, H) REP(k1, k0 + 1, H + 1) REP(l0, 0, j0) REP(l1, l0 + 1, j0 + 1) {
      ll t = area(k0, k1, l0, l1);
      updMax(ans, s + t);
    }
    REP(k0, 0, H) REP(k1, k0 + 1, H + 1) REP(l0, j1, W) REP(l1, l0 + 1, W + 1) {
      ll t = area(k0, k1, l0, l1);
      updMax(ans, s + t);
    }
  }
  cout << ans << "\n";

  return 0;
}

int body(istream& cin, ostream& cout) {

  ll H, W; cin >> H >> W;
  // @InpGrid(H, W, B) [K06UFXfE]
  auto B = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; B[i][j] = v; }
  // @End [K06UFXfE]

  ll npc = 0;
  REP(i, 0, H) REP(j, 0, W) if (B[i][j] > 0) npc++;
  if (npc <= 1) {
    vector<ll> tmp;
    REP(i, 0, H) REP(j, 0, W) tmp.push_back(B[i][j]);
    sort(ALL(tmp), greater<ll>());
    cout << tmp[0] + tmp[1] << endl;
    return 0;
  }
  vector S(H + 1, vector(W + 1, 0LL));
  REP(i, 1, H + 1) REP(j, 1, W + 1) S[i][j] = B[i - 1][j - 1];
  REP(i, 1, H + 1) REP(j, 1, W + 1) S[i][j] += S[i][j - 1];
  REP(j, 1, W + 1) REP(i, 1, H + 1) S[i][j] += S[i - 1][j];
  DLOGK(S);

  using sta = tuple<ll, vector<ll>, vector<ll>, vector<ll>>;
  auto calcMax = [&](bool isH, ll k0, ll k1, ll LenT, ll LenO) -> sta {
    vector T(LenO + 1, 0LL);
    vector U(LenO + 1, 0LL);
    vector V(LenO + 1, 0LL);
    if (isH) REP(j, 0, LenO + 1) T[j] = S[k0][0] + S[k1][j] - (S[k0][j] + S[k1][0]);
    else     REP(j, 0, LenO + 1) T[j] = S[0][k0] + S[j][k1] - (S[j][k0] + S[0][k1]);
    U[0] = T[0];
    V[0] = 0;
    REP(j, 1, LenO + 1) {
      if (T[j] <= U[j - 1]) { U[j] = T[j];  V[j] = j; }
      else                  { U[j] = U[j - 1]; V[j] = V[j - 1]; }
    }
    ll mx = 0;
    REP(j, 1, LenO + 1) mx = max(mx, T[j] - U[j]);
    return {mx, move(T), move(U), move(V)};
  };

  vector Hmx(H + 1, vector(H + 1, 0LL));
  REP(i0, 0, H + 1) REP(i1, i0 + 1, H + 1) {
    auto [t, dum1, dum2, dum3] = calcMax(true, i0, i1, H, W);
    Hmx[i0][i1] = t;
  }
  vector Wmx(W + 1, vector(W + 1, 0LL));
  REP(j0, 0, W + 1) REP(j1, j0 + 1, W + 1) {
    auto [t, dum1, dum2, dum3] = calcMax(false, j0, j1, W, H);
    Wmx[j0][j1] = t;
  }
  DLOGK(Hmx);
  DLOGK(Wmx);

  vector Hmy(H + 1, vector(H + 1, -1LL));
  vector Wmy(W + 1, vector(W + 1, -1LL));
  auto calc = [&](auto rF, auto& y, auto& x, ll k0, ll k1) -> void {
    if (y[k0][k1] >= 0) return;
    if (k0 + 1 == k1) {
      y[k0][k1] = x[k0][k1];
      return;
    }
    rF(rF, y, x, k0, k1 - 1);
    rF(rF, y, x, k0 + 1, k1);
    y[k0][k1] = max(x[k0][k1], max(y[k0][k1 - 1], y[k0 + 1][k1]));
  };
  calc(calc, Hmy, Hmx, 0, H);
  calc(calc, Wmy, Wmx, 0, W);
  DLOGK(Hmy);
  DLOGK(Wmy);

  auto func = [&](bool isH, ll k0, ll k1, ll vmax, 
                  ll LenT, ll LenO, const auto& my, const auto& myO) -> ll {
    if (vmax == 0) return 0;
    ll ret = 0;
    auto [t, T, U, V] = calcMax(isH, k0, k1, LenT, LenO);
    REP(j, 1, SIZE(T)) {
      if (T[j] - U[j] == vmax and T[j - 1] < T[j]) {
        ll a = 0;
        updMax(a, my[0][k0]);
        updMax(a, my[k1][LenT]);
        updMax(a, myO[0][V[j]]);
        updMax(a, myO[j][LenO]);
        DLOGK(isH, k0, k1, j, V[j], vmax, a, my[0][k0], my[k0][LenT], myO[0][V[j]], myO[j][LenO]);
        if (a > 0) updMax(ret, vmax + a);
      }
    }
    return ret;
  };

  ll ans = 0;
  REP(i0, 0, H + 1) REP(i1, i0 + 1, H + 1) {
    updMax(ans, func(true, i0, i1, Hmy[i0][i1], H, W, Hmy, Wmy));

  }
  REP(j0, 0, W + 1) REP(j1, j0 + 1, W + 1) {
    updMax(ans, func(false, j0, j1, Wmy[j0][j1], W, H, Wmy, Hmy));
  }
  cout << ans << endl;

  return 0;
}

