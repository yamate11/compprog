#pragma region header
#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

#define INT(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  in(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define VEC(type, name, size) \
  vector<type> name(size);    \
  in(name)
[[maybe_unused]] void print() {}
template <class T, class... Ts>
void print(const T& t, const Ts&... ts);
template <class... Ts>
void out(const Ts&... ts) {
  print(ts...);
  cout << '\n';
}

namespace IO {
#define VOID(a) decltype(void(a))
struct S {
  S() {
    cin.tie(nullptr)->sync_with_stdio(0);
    fixed(cout).precision(12);
  }
} S;
template <int I>
struct P : P<I - 1> {};
template <>
struct P<0> {};
template <class T>
void i(T& t) {
  i(t, P<3>{});
}
void i(vector<bool>::reference t, P<3>) {
  int a;
  i(a);
  t = a;
}
template <class T>
auto i(T& t, P<2>) -> VOID(cin >> t) {
  cin >> t;
}
template <class T>
auto i(T& t, P<1>) -> VOID(begin(t)) {
  for (auto&& x : t) i(x);
}
template <class T, size_t... idx>
void ituple(T& t, index_sequence<idx...>) {
  in(get<idx>(t)...);
}
template <class T>
auto i(T& t, P<0>) -> VOID(tuple_size<T>{}) {
  ituple(t, make_index_sequence<tuple_size<T>::value>{});
}
template <class T>
void o(const T& t) {
  o(t, P<4>{});
}
template <size_t N>
void o(const char (&t)[N], P<4>) {
  cout << t;
}
template <class T, size_t N>
void o(const T (&t)[N], P<3>) {
  o(t[0]);
  for (size_t i = 1; i < N; i++) {
    o(' ');
    o(t[i]);
  }
}
template <class T>
auto o(const T& t, P<2>) -> VOID(cout << t) {
  cout << t;
}
template <class T>
auto o(const T& t, P<1>) -> VOID(begin(t)) {
  bool first = 1;
  for (auto&& x : t) {
    if (first)
      first = 0;
    else
      o(' ');
    o(x);
  }
}
template <class T, size_t... idx>
void otuple(const T& t, index_sequence<idx...>) {
  print(get<idx>(t)...);
}
template <class T>
auto o(T& t, P<0>) -> VOID(tuple_size<T>{}) {
  otuple(t, make_index_sequence<tuple_size<T>::value>{});
}
#undef VOID
}  // namespace IO
#define unpack(a) \
  (void)initializer_list<int> { (a, 0)... }
template <class... Ts>
void in(Ts&... t) {
  unpack(IO::i(t));
}
template <class T, class... Ts>
void print(const T& t, const Ts&... ts) {
  IO::o(t);
  unpack(IO::o((cout << ' ', ts)));
}
#undef unpack

#define YESNO(yes, no)                          \
  void yes(bool i = 1) { out(i ? #yes : #no); } \
  void no() { out(#no); }
YESNO(first, second)
YESNO(First, Second)
YESNO(Yes, No)
YESNO(YES, NO)
YESNO(possible, impossible)
YESNO(POSSIBLE, IMPOSSIBLE)

template <typename T>
inline bool chmax(T& a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T& a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}
#pragma endregion header
#include <atcoder/all>
using namespace atcoder;

// 二項演算S op(S a, S b)
int op(int a, int b) { return a + b; }
// 単位元 S e()
int e() { return 0; }

int main() {
  /* input */
  INT(N, M, K);
  STR(T);
  VEC(string, S, N);
  debug(S);
  T.push_back('o');
  rep(i, N) S[i].push_back('x');

  segtree<int, op, e> seg_obj(K);
  vector segs(N, seg_obj);
  // vector<segtree<int, op, e>> segs(N, K);  // A(N, e)で初期化
  rep(i, N) rep(j, K) {
    if (S[i][j] == T[j]) segs[i].set(j, 1);
  }
  segtree<int, op, e> seg2(K + 10);
  vi vec(N);

  rep(i, N) {
    rep(j, K + 1) {
      if (S[i][j] != T[j]) {
        seg2.set(j, seg2.get(j) + 1);
        vec[i] = j;
        break;
      }
    }
  }
  debug(vec);

  /* solve */

  INT(Q);
  rep(qi, Q) {
    INT(i, j);
    i--, j--;
    debug(qi, i, j);
    if (S[i][j] == 'o') {
      S[i][j] = 'x';
    } else {
      S[i][j] = 'o';
    }
    debug(S);

    segs[i].set(j, segs[i].get(j) ^ 1);

    // 先頭のng個が1
    int ok = K + 1, ng = -1;
    while (ok - ng > 1) {
      int mid = (ok + ng) / 2;

      if (segs[i].prod(0, mid) == mid) {
        ng = mid;
      } else {
        ok = mid;
      }
    }
    debug(qi, ng);

    if (vec[i] != ng) {
      seg2.set(vec[i], seg2.get(vec[i]) - 1);
      vec[i] = ng;
      seg2.set(vec[i], seg2.get(vec[i]) + 1);
    }

    // Yes(seg2.prod(vec[i] + 1, K + 1) < M);
    int ng2 = -1, ok2 = K + 1;
    while (ok2 - ng2 > 1) {
      int mid = (ok2 + ng2) / 2;

      if (seg2.prod(mid, K + 1) <= M) {
        ok2 = mid;
      } else {
        ng2 = mid;
      }
    }

    if (ok2 == 0 && K < M) {
      out("No");
      continue;
    }

    debug(vec, ng2);
    Yes(ok2 <= vec[i]);
  }

  /* output */
}
