#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cmpNaive debug)
// --> cmpNaive f:<< debug
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
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {

  ll n, m; cin >> n >> m;
  vector<ll> A(n + 1);
  for (ll i = 1; i <= n; i++) {
    ll a; cin >> a;
    A[i] = a;
  }
  for (ll _q = 0; _q < m; _q++) {
    ll ty; cin >> ty;
    if (ty == 1) {
      ll p, x; cin >> p >> x;
      A[p] = x;
    }else if (ty == 2) {
      ll l, r; cin >> l >> r;
      vector<ll> rec1(n + 1, -1), rec2(n + 1, -1);
      for (ll i = l; i <= r; i++) {
        ll c = A[i];
        if (rec1[c] < 0) rec1[c] = i;
        rec2[c] = i;
      }
      ll s = 0;
      for (ll i = 1; i <= n; i++) {
        if (rec2[i] >= 0) s += rec2[i] - rec1[i];
      }
      cout << s << "\n";
    }
  }



  return 0;
}

struct STNode {
  ll val;
  STNode* lolo;
  STNode* lohi;
  STNode* hilo;
  STNode* hihi;

  STNode() : val(0), lolo(0), lohi(0), hilo(0), hihi(0) {}

  ll n_query(ll left1, ll right1, ll left2, ll right2,
             ll l1, ll r1, ll l2, ll r2) {
    if (right1 <= l1 || r1 <= left1 || right2 <= l2 || r2 <= left2) {
      return 0;
    }
    if (left1 <= l1 && r1 <= right1 && left2 <= l2 && r2 <= right2) {
      return val;
    }
    ll m1 = (l1 + r1) / 2;
    ll m2 = (l2 + r2) / 2;
    auto sub = [&](STNode* nd, ll x1, ll y1, ll x2, ll y2) -> ll {
      if (!nd) return 0;
      return nd->n_query(left1, right1, left2, right2, x1, y1, x2, y2);
    };
    ll vlolo = sub(lolo, l1, m1, l2, m2);
    ll vlohi = sub(lohi, l1, m1, m2, r2);
    ll vhilo = sub(hilo, m1, r1, l2, m2);
    ll vhihi = sub(hihi, m1, r1, m2, r2);
    return vlolo + vlohi + vhilo + vhihi;
  };

  void n_update(ll x1, ll x2, ll v,
                ll l1, ll r1, ll l2, ll r2) {
    if (l1 + 1 == r1 && l2 + 1 == r2) {
      assert(l1 == x1 && l2 == x2);
      val = v;
    }else {
      ll m1 = (l1 + r1) / 2;
      ll m2 = (l2 + r2) / 2;
      using pt_t = STNode*;
      auto sub = [&](pt_t& nd, ll t1, ll s1, ll t2, ll s2) -> void {
        if (!nd) nd = new STNode();
        nd->n_update(x1, x2, v, t1, s1, t2, s2);
      };
      if (x1 <  m1 && x2 <  m2) sub(lolo, l1, m1, l2, m2);
      if (x1 <  m1 && x2 >= m2) sub(lohi, l1, m1, m2, r2);
      if (x1 >= m1 && x2 <  m2) sub(hilo, m1, r1, l2, m2);
      if (x1 >= m1 && x2 >= m2) sub(hihi, m1, r1, m2, r2);
      auto eval = [&](pt_t nd) -> ll { return nd ? nd->val : 0; };
      val = eval(lolo) + eval(lohi) + eval(hilo) + eval(hihi);
    }
  }
};

struct SegTree {
  ll lbnd1;
  ll rbnd1;
  ll lbnd2;
  ll rbnd2;
  STNode* top;

  ll query(ll left1, ll right1, ll left2, ll right2) {
    return top->n_query(left1, right1, left2, right2,
                        lbnd1, rbnd1, lbnd2, rbnd2);
  }

  void update(ll x1, ll x2, ll v) {
    DLOGKL("st.update", x1, x2, v);
    top->n_update(x1, x2, v,
                  lbnd1, rbnd1, lbnd2, rbnd2);
  }

  SegTree(ll lb1, ll rb1, ll lb2, ll rb2)
    : lbnd1(lb1), rbnd1(rb1), lbnd2(lb2), rbnd2(rb2) {
    top = new STNode();
  }
};

int body(istream& cin, ostream& cout) {

  ll n, m; cin >> n >> m;
  SegTree st(1, n + 1, 1, n + 1);
  vector<ll> A(n + 1);
  vector<set<ll>> pos(n + 1, {0, n + 1});
  for (ll i = 1; i <= n; i++) {
    ll a; cin >> a;
    A[i] = a;
    pos[a].insert(i);
  }
  vector<ll> prev(n + 1, -1), next(n + 1, -1), rec(n + 1, -1);
  for (ll i = 1; i <= n; i++) {
    ll c = A[i];
    if (rec[c] >= 0) {
      st.update(i, rec[c], i - rec[c]);
      next[rec[c]] = i;
      prev[i] = rec[c];
    }
    rec[c] = i;
  }
  for (ll _q = 0; _q < m; _q++) {
    ll ty; cin >> ty;
    if (ty == 1) {
      ll p, x; cin >> p >> x;
      DLOGKL("ty1 in", p, x);
      ll old_x = A[p];
      if (x == old_x) continue;
      ll opr = prev[p];
      ll onx = next[p];
      if (opr >= 0) {
        st.update(p, opr, 0);
        if (onx >= 0) {
          st.update(onx, p, 0);
          st.update(onx, opr, onx - opr);
          prev[onx] = opr;
          next[opr] = onx;
        }else {
          next[opr] = -1;
        }
      }else {
        if (onx >= 0) {
          st.update(onx, p, 0);
          prev[onx] = -1;
        }
      }
      next[p] = prev[p] = -1;
      pos[old_x].erase(p);
      auto it1 = pos[x].lower_bound(p);
      ll nx = *it1--;
      ll pr = *it1;
      if (nx <= n && pr >= 1) {
        st.update(nx, pr, 0);
      }
      if (nx <= n) {
        st.update(nx, p, nx - p);
        next[p] = nx;
        prev[nx] = p;
      }
      if (pr >= 1) {
        st.update(p, pr, p - pr);
        prev[p] = pr;
        next[pr] = p;
      }
      A[p] = x;
      pos[x].insert(p);
      DLOGKL("ty1", prev, next, A);
    }else if (ty == 2) {
      ll l, r; cin >> l >> r;
      ll v = st.query(l, r + 1, l, n + 1);
      cout << v << "\n";
    }
  }
  

  return 0;
}

