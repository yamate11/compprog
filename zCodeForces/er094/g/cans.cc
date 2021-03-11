#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define CONSTANT_MOD 998244353

// @@ !! LIM(mod debug cmpNaive)
// --> f:gcd f:intDiv mod f:<< debug cmpNaive
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}
// ---- end gcd
// ---- inserted function intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}

// ---- end intDiv
// ---- inserted library file mod.cc

/*
  You may want to put something like:
#define CONSTANT_MOD (1e9 + 7)
#define CONSTANT_MOD 998244353
  in the header part (outside of library paste area)
 */

struct Fp {
#if defined(CONSTANT_MOD)
  static const ll MOD = CONSTANT_MOD;
#else
  static ll MOD;
#endif

  ll val;

  /*
  ll _calc_from_ll(ll t = 0) {
    if      (t >= MOD)  return t % MOD;
    else if (t >= 0)    return t;
    else if (t >= -MOD) return t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) return 0;
      else        return v + MOD;
    }
  }
  */

  Fp(ll t = 0) : val(imod(t, MOD)) {}
  Fp(const Fp& t) : val(t.val) {}
  Fp& operator =(const Fp& t) { val = t.val; return *this; }
  Fp& operator =(ll t) { val = imod(t, MOD); return *this; }
  Fp& operator =(int t) { val = imod(t, MOD); return *this; }

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Fp operator +(int x, const Fp& y) { return Fp(x) + y; }
Fp operator -(int x, const Fp& y) { return Fp(x) - y; }
Fp operator *(int x, const Fp& y) { return Fp(x) * y; }
Fp operator /(int x, const Fp& y) { return Fp(x) / y; }
Fp operator +(ll x, const Fp& y) { return Fp(x) + y; }
Fp operator -(ll x, const Fp& y) { return Fp(x) - y; }
Fp operator *(ll x, const Fp& y) { return Fp(x) * y; }
Fp operator /(ll x, const Fp& y) { return Fp(x) / y; }
Fp operator +(const Fp& x, int y) { return x + Fp(y); }
Fp operator -(const Fp& x, int y) { return x - Fp(y); }
Fp operator *(const Fp& x, int y) { return x * Fp(y); }
Fp operator /(const Fp& x, int y) { return x / Fp(y); }
Fp operator +(const Fp& x, ll y) { return x + Fp(y); }
Fp operator -(const Fp& x, ll y) { return x - Fp(y); }
Fp operator *(const Fp& x, ll y) { return x * Fp(y); }
Fp operator /(const Fp& x, ll y) { return x / Fp(y); }

istream& operator>> (istream& is, Fp& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Fp& t) {
  os << t.val;
  return os;
}

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

#if !defined(CONSTANT_MOD)
ll Fp::MOD = 1e9 + 7;
// ll Fp::MOD = 998'244'353;
#endif

// ---- end mod.cc
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
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

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

// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --


int naive(istream& cin, ostream& cout) {
  ll n, m; cin >> n >> m;
  vector<ll> L(n), R(n), A(m), B(m);
  for (ll i = 0; i < n; i++) cin >> L[i] >> R[i]; 
  for (ll i = 0; i < m; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    A[i] = a;
    B[i] = b;
  }
  auto check = [&](ll x) -> bool {
    ll popul = __builtin_popcountll(x);
    for (ll i = 0; i < n; i++) {
      if (!((x >> i) & 1)) continue;
      if (popul < L[i] || R[i] < popul) return false;
    }
    for (ll i = 0; i < m; i++) {
      if (((x >> A[i]) & 1) && ((x >> B[i]) & 1)) return false;
    }
    return true;
  };
  ll cnt = 0;
  for (ll x = 1; x < (1LL << n); x++) cnt += check(x) ? 1 : 0;
  cout << cnt << endl;
  

  return 0;
}


int body(istream& cin, ostream& cout) {

  ll n, m; cin >> n >> m;
  vector<ll> L(n), R(n);
  vector<ll> add(n+2), rem(n+2);
  for (ll i = 0; i < n; i++) {
    cin >> L[i] >> R[i]; R[i]++;
    add[L[i]]++;
    rem[R[i]]++;
  }
  vector<ll> prob;
  vector<ll> rev_prob(n, -1);
  vector<ll> hate;
  vector<vector<ll>> add_prob(n+2), rem_prob(n+2);
  ll idx = 0;

  DLOG("add=", add);
  DLOG("rem=", rem);

  auto prob_idx = [&](ll x) -> ll {
    ll& ret = rev_prob[x];
    if (ret == -1) {
      prob.push_back(x);
      hate.push_back(0);
      ret = idx;
      idx++;
    }
    return ret;
  };
  for (ll i = 0; i < m; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    ll idx_a = prob_idx(a);
    ll idx_b = prob_idx(b);
    hate[idx_a] |= (1LL << idx_b);
    hate[idx_b] |= (1LL << idx_a);
  }
  ll num_all_prob = prob.size();
  for (ll i = 0; i < num_all_prob; i++) {
    add_prob[L[prob[i]]].push_back(i);
    rem_prob[R[prob[i]]].push_back(i);
  }
  DLOG("prob", prob, "rev_prob", rev_prob,
       "add_prob", add_prob, "rem_prob", rem_prob,
       "hate", hate);

  ll popul = 0;
  ll set_prob = 0;
  ll num_cur_prob = 0;
  vector<ll> comb_prob({1});
  Comb cb(n);

  auto upd_prob = [&](auto rF, ll k, ll x, ll ban) -> void {
    while (k < num_all_prob &&
	   (!((set_prob >> k) & 1) || ((ban >> k) & 1))) k++;
    if (k == num_all_prob) {
      comb_prob[__builtin_popcountll(x)]++;
      return;
    }
    rF(rF, k + 1, x, ban);
    rF(rF, k + 1, x | (1LL << k), ban | hate[k]);
  };

  Fp ans = 0;
  for (ll i = 1; i <= n; i++) {
    if (rem[i] > 0 || add[i] > 0) popul += add[i] - rem[i];
    if (rem_prob[i].size() > 0 || add_prob[i].size() > 0) {
      for (ll j : rem_prob[i]) {
	set_prob &= ~(1LL << j);
	num_cur_prob--;
      }
      for (ll j : add_prob[i]) {
	set_prob |= (1LL << j);
	num_cur_prob++;
      }
      comb_prob = vector<ll>(num_cur_prob + 1);
      upd_prob(upd_prob, 0, 0, 0);
      DLOG("i=", i, "set_prob=", set_prob, "comb_prob=", comb_prob);
    }
    if (popul < i) continue;
    Fp cnt = 0;
    for (ll j = 0; j <= min(i, num_cur_prob); j++) {
      ll pmn = popul - num_cur_prob;
      ll k = i - j;
      if (k > pmn) continue;
      Fp n1 = cb.comb(pmn, k);
      Fp n2 = comb_prob[j];
      DLOG("j=", j, "n1=", n1, "n2=", n2);
      cnt += n1 * n2;
    }
    DLOG("i=", i, "cnt=", cnt);
    ans += cnt;
  }
  cout << ans << endl;

  return 0;
}

