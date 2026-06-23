#line 2 "library/template/template.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 2 "library/template/macro.hpp"
#define rep(i, a, b) for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())
#define SZ(v) (int)v.size()
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))
#define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())
#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())
#define YN(b) cout << ((b) ? "YES" : "NO") << "\n";
#define Yn(b) cout << ((b) ? "Yes" : "No") << "\n";
#define yn(b) cout << ((b) ? "yes" : "no") << "\n";
#line 6 "library/template/template.hpp"

#line 2 "library/template/util.hpp"
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;

template <class T, class S = T>
S SUM(const vector<T>& a) {
  return accumulate(ALL(a), S(0));
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
int popcnt(T x) {
  return __builtin_popcountll(x);
}
template <class T>
int topbit(T x) {
  return (x == 0 ? -1 : 63 - __builtin_clzll(x));
}
template <class T>
int lowbit(T x) {
  return (x == 0 ? -1 : __builtin_ctzll(x));
}
#line 8 "library/template/template.hpp"

#line 2 "library/template/inout.hpp"
struct Fast {
  Fast() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} fast;

ostream& operator<<(ostream& os, __uint128_t x) {
  char buf[40];
  size_t k = 0;
  while (x > 0) buf[k++] = (char)(x % 10 + '0'), x /= 10;
  if (k == 0) buf[k++] = '0';
  while (k) os << buf[--k];
  return os;
}
ostream& operator<<(ostream& os, __int128_t x) {
  return x < 0 ? (os << '-' << (__uint128_t)(-x)) : (os << (__uint128_t)x);
}
template <class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  return is >> p.first >> p.second;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << p.first << " " << p.second;
}
template <class T>
istream& operator>>(istream& is, vector<T>& a) {
  for (auto& v : a) is >> v;
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  for (auto it = a.begin(); it != a.end();) {
    os << *it;
    if (++it != a.end()) os << " ";
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& st) {
  os << "{";
  for (auto it = st.begin(); it != st.end();) {
    os << *it;
    if (++it != st.end()) os << ",";
  }
  os << "}";
  return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const map<T1, T2>& mp) {
  os << "{";
  for (auto it = mp.begin(); it != mp.end();) {
    os << it->first << ":" << it->second;
    if (++it != mp.end()) os << ",";
  }
  os << "}";
  return os;
}

void in() {}
template <typename T, class... U>
void in(T& t, U&... u) {
  cin >> t;
  in(u...);
}
void out() { cout << "\n"; }
template <typename T, class... U, char sep = ' '>
void out(const T& t, const U&... u) {
  cout << t;
  if (sizeof...(u)) cout << sep;
  out(u...);
}

namespace IO {
namespace Graph {
vector<vector<int>> unweighted(int n, int m, bool directed = false, int offset = 1) {
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u -= offset, v -= offset;
    g[u].push_back(v);
    if (!directed) g[v].push_back(u);
  }
  return g;
}
template <class T>
vector<vector<pair<int, T>>> weighted(int n, int m, bool directed = false, int offset = 1) {
  vector<vector<pair<int, T>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    T w;
    cin >> u >> v >> w;
    u -= offset, v -= offset;
    g[u].push_back({v, w});
    if (!directed) g[v].push_back({u, w});
  }
  return g;
}
}  // namespace Graph
namespace Tree {
vector<vector<int>> unweighted(int n, bool directed = false, int offset = 1) {
  return Graph::unweighted(n, n - 1, directed, offset);
}
template <class T>
vector<vector<pair<int, T>>> weighted(int n, bool directed = false, int offset = 1) {
  return Graph::weighted<T>(n, n - 1, directed, offset);
}
vector<vector<int>> rooted(int n, bool to_root = true, bool to_leaf = true, int offset = 1) {
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p -= offset;
    if (to_root) g[i].push_back(p);
    if (to_leaf) g[p].push_back(i);
  }
  return g;
}
}  // namespace Tree
}  // namespace IO
#line 10 "library/template/template.hpp"

#line 2 "library/template/debug.hpp"
#ifdef LOCAL
#define debug 1
#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug 0
#define show(...) true
#endif
template <class T>
void _show(int i, T name) {
  cerr << '\n';
}
template <class T1, class T2, class... T3>
void _show(int i, const T1& a, const T2& b, const T3&... c) {
  for (; a[i] != ',' && a[i] != '\0'; i++) cerr << a[i];
  cerr << ":" << b << " ";
  _show(i + 1, a, c...);
}
#line 2 "main.cpp"

void solve() {
  int N;
  ll B;
  in(N, B);
  vector<ll> P(N), C(N - 1);
  in(P, C);

  ll ans = 0;
  ll s = P[0], c = 0;
  int r = 0;
  rep(l, 0, N - 1) {
    while (r < N - 1 && c + C[r] <= B) {
      s += P[r + 1];
      c += C[r];
      r++;
    }
    chmax(ans, s);
    s -= P[l];
    c -= C[l];
  }
  out(ans);
}

int main() {
  int t = 1;
  // in(t);
  while (t--) solve();
}
