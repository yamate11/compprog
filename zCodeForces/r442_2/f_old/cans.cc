#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug cmpNaive)
// --> f:<< debug cmpNaive
// ---- inserted function << from util.cc
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

// ---- end <<
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

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

// ---- end debug.cc
// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");
const string end_file_mark("^__=end_file=__^");

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
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll n, k; cin >> n >> k;
  vector<ll> TP(n + 1), A(n + 1);
  for (ll i = 1; i <= n; i++) cin >> TP[i];
  for (ll i = 1; i <= n; i++) {
    ll a; cin >> a;
    A[i] = TP[i] == 1 ? a : -a;
  }
  ll q; cin >> q;
  for (ll _q = 0; _q < q; _q++) {
    ll cnt = 0;
    ll l, r; cin >> l >> r;
    for (ll x = l; x <= r; x++) {
      for (ll y = x; y <= r; y++) {
        ll v = 0;
        for (ll z = x; z <= y; z++) v += A[z];
        if (v == k) cnt++;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
int body(istream& cin, ostream& cout) {
  ll n, k; cin >> n >> k;
  vector<ll> TP(n), A(n), S(n + 1);
  for (ll i = 0; i < n; i++) cin >> TP[i];
  ll seq = 2;
  map<ll, ll> enc({{0, 1}});
  vector<ll> dec({0, 0});
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = TP[i] == 1 ? a : -a;
    S[i + 1] = S[i] + A[i];
    if (enc.find(S[i + 1]) == enc.end()) {
      enc[S[i + 1]] = seq++;
      dec.push_back(S[i + 1]);
    }
  }
  ll esize = dec.size();
  vector<ll> plusk(esize), minusk(esize);
  for (ll i = 0; i < esize; i++) {
    auto it1 = enc.find(dec[i] + k);
    if (it1 != enc.end()) plusk[i] = it1->second;
    else                  plusk[i] = 0;
    auto it2 = enc.find(dec[i] - k);
    if (it2 != enc.end()) minusk[i] = it2->second;
    else                  minusk[i] = 0;
  }
  DLOGK(enc);
  DLOGK(dec);
  DLOGK(plusk);
  DLOGK(minusk);
  vector<ll> T(n + 1);
  for (ll i = 0; i <= n; i++) T[i] = enc[S[i]];
  DLOGK(T);

  ll q; cin >> q;
  using stp = tuple<ll, ll, ll>;
  vector<stp> LR;
  for (ll i = 0; i < q; i++) {
    ll l, r; cin >> l >> r; l--; r++;
    LR.emplace_back(l, r, i);
  }
  sort(LR.begin(), LR.end());
  DLOGK(S);
  vector<ll> ans(q);
  ll sq = floor(sqrt(q)) + 1;
  ll sidx = 0;
  for ( ; sidx < q ; sidx += sq) {
    ll nsidx = min(sidx + sq, q);
    vector<stp> TLR(nsidx - sidx);
    copy(LR.begin() + sidx, LR.begin() + nsidx, TLR.begin());
    sort(TLR.begin(), TLR.end(),
         [&](const stp& a, const stp& b) -> bool {
           auto [al, ar, ai] = a;
           auto [bl, br, bi] = b;
           return ar < br;
         });
    // map<ll, ll> mp;
    // unordered_map<ll, ll> mp;
    vector<ll> cnt(esize);
    ll val = 0;
    ll jl = 0, jr = 0;
    DLOGKL("val", val);
    for (auto [l, r, i] : TLR) {
      DLOGK(l, r, i);
      while (jr < r) {
        val += cnt[minusk[T[jr]]];
        cnt[T[jr]]++;
        jr++;
        DLOGKL("a", jr, val, cnt);
      }
      if (jl < l) {
        while (jl < l) {
          cnt[T[jl]]--;
          val -= cnt[plusk[T[jl]]];
          jl++;
          DLOGKL("b", jl, val, cnt);
        }
      }else if (l < jl) {
        while (l < jl) {
          jl--;
          val += cnt[plusk[T[jl]]];
          cnt[T[jl]]++;
          DLOGKL("c", jl, val, cnt);
        }
      }
      ans[i] = val;
    }
  }
  for (ll i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}

