#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }
#define COLOR(s) ("\x1b[" s "m")

// T: monoid representing information of an interval.
//   T()  should return the identity.
//   T(S s)  should represent a single element of the array.
//   T::pull(const T &l, const T &r)  should pull two intervals.
template <class T> struct SegmentTreePoint {
  int logN, n;
  vector<T> ts;
  SegmentTreePoint() : logN(0), n(0) {}
  explicit SegmentTreePoint(int n_) {
    for (logN = 0, n = 1; n < n_; ++logN, n <<= 1) {}
    ts.resize(n << 1);
  }
  template <class S> explicit SegmentTreePoint(const vector<S> &ss) {
    const int n_ = ss.size();
    for (logN = 0, n = 1; n < n_; ++logN, n <<= 1) {}
    ts.resize(n << 1);
    for (int i = 0; i < n_; ++i) at(i) = T(ss[i]);
    build();
  }
  T &at(int i) {
    return ts[n + i];
  }
  void build() {
    for (int u = n; --u; ) pull(u);
  }

  inline void pull(int u) {
    ts[u].pull(ts[u << 1], ts[u << 1 | 1]);
  }

  // Changes the value of point a to s.
  template <class S> void change(int a, const S &s) {
    assert(0 <= a); assert(a < n);
    ts[a += n] = T(s);
    for (; a >>= 1; ) pull(a);
  }

  // Applies T::f(args...) to point a.
  template <class F, class... Args>
  void ch(int a, F f, Args &&... args) {
    assert(0 <= a); assert(a < n);
    (ts[a += n].*f)(args...);
    for (; a >>= 1; ) pull(a);
  }

  // Calculates the product for [a, b).
  T get(int a, int b) {
    assert(0 <= a); assert(a <= b); assert(b <= n);
    if (a == b) return T();
    a += n; b += n;
    T prodL, prodR, t;
    for (int aa = a, bb = b; aa < bb; aa >>= 1, bb >>= 1) {
      if (aa & 1) { t.pull(prodL, ts[aa++]); prodL = t; }
      if (bb & 1) { t.pull(ts[--bb], prodR); prodR = t; }
    }
    t.pull(prodL, prodR);
    return t;
  }

  // Calculates T::f(args...) of a monoid type for [a, b).
  //   op(-, -)  should calculate the product.
  //   e()  should return the identity.
  template <class Op, class E, class F, class... Args>
#if __cplusplus >= 201402L
  auto
#else
  decltype((std::declval<T>().*F())())
#endif
  get(int a, int b, Op op, E e, F f, Args &&... args) {
    assert(0 <= a); assert(a <= b); assert(b <= n);
    if (a == b) return e();
    a += n; b += n;
    auto prodL = e(), prodR = e();
    for (int aa = a, bb = b; aa < bb; aa >>= 1, bb >>= 1) {
      if (aa & 1) prodL = op(prodL, (ts[aa++].*f)(args...));
      if (bb & 1) prodR = op((ts[--bb].*f)(args...), prodR);
    }
    return op(prodL, prodR);
  }

  // Find min b s.t. T::f(args...) returns true,
  // when called for the partition of [a, b) from left to right.
  //   Returns n + 1 if there is no such b.
  template <class F, class... Args>
  int findRight(int a, F f, Args &&... args) {
    assert(0 <= a); assert(a <= n);
    if ((T().*f)(args...)) return a;
    if (a == n) return n + 1;
    a += n;
    for (; ; a >>= 1) if (a & 1) {
      if ((ts[a].*f)(args...)) {
        for (; a < n; ) {
          if (!(ts[a <<= 1].*f)(args...)) ++a;
        }
        return a - n + 1;
      }
      ++a;
      if (!(a & (a - 1))) return n + 1;
    }
  }

  // Find max a s.t. T::f(args...) returns true,
  // when called for the partition of [a, b) from right to left.
  //   Returns -1 if there is no such a.
  template <class F, class... Args>
  int findLeft(int b, F f, Args &&... args) {
    assert(0 <= b); assert(b <= n);
    if ((T().*f)(args...)) return b;
    if (b == 0) return -1;
    b += n;
    for (; ; b >>= 1) if ((b & 1) || b == 2) {
      if ((ts[b - 1].*f)(args...)) {
        for (; b <= n; ) {
          if (!(ts[(b <<= 1) - 1].*f)(args...)) --b;
        }
        return b - n - 1;
      }
      --b;
      if (!(b & (b - 1))) return -1;
    }
  }
};

////////////////////////////////////////////////////////////////////////////////


constexpr int INF = 1001001001;

int V;
struct Node {
  int ans, cost;
  int preLen, sufLen;
  pair<int, int> pre[33], suf[33];
  Node() : ans(INF), cost(-INF), preLen(1), sufLen(1), pre{}, suf{} {
    pre[0] = suf[0] = make_pair(-INF, 0);
  }
  Node(int a, int b) : ans(INF), cost(a), preLen(1), sufLen(1), pre{}, suf{} {
    if (b >= V) ans = a;
    pre[0] = suf[0] = make_pair(-INF, 0);
    if (b) {
      preLen = sufLen = 2;
      pre[1] = suf[1] = make_pair(a, b);
    }
  }
  friend ostream &operator<<(ostream &os, const Node &t) {
    os << "(ans=" << t.ans << ", |pre|=" << t.preLen << ", pre=";
    for (int i = 0; i < t.preLen; ++i) os << " " << t.pre[i];
    os << ", |suf|=" << t.sufLen << ", suf=";
    for (int i = 0; i < t.sufLen; ++i) os << " " << t.suf[i];
    os << ")";
    return os;
  }
  void pull(const Node &l, const Node &r) {
    ans = min(l.ans, r.ans);
    cost = max(l.cost, r.cost);
    preLen = l.preLen;
    copy(l.pre, l.pre + l.preLen, pre);
    {
      int a = l.cost;
      int b = pre[preLen - 1].second;
      for (int j = 0; j < r.preLen; ++j) {
        chmax(a, r.pre[j].first);
        const int bb = b | r.pre[j].second;
        if (b < bb) {
          b = bb;
          pre[preLen++] = make_pair(a, b);
        }
      }
    }
    sufLen = r.sufLen;
    copy(r.suf, r.suf + r.sufLen, suf);
    {
      int a = r.cost;
      int b = suf[sufLen - 1].second;
      for (int i = 0; i < l.sufLen; ++i) {
        chmax(a, l.suf[i].first);
        const int bb = b | l.suf[i].second;
        if (b < bb) {
          b = bb;
          suf[sufLen++] = make_pair(a, b);
        }
      }
    }
    for (int i = l.sufLen, j = 0; --i >= 0; ) {
      for (; j < r.preLen && (l.suf[i].second | r.pre[j].second) < V; ++j) {}
      if (j < r.preLen) {
// if(max(l.suf[i].first, r.pre[j].first)==32)cerr<<"HELP! "<<i<<" "<<j<<" "<<l.suf[i]<<" "<<r.pre[j]<<endl<<"  "<<l<<endl<<"  "<<r<<endl;
        chmin(ans, max(l.suf[i].first, r.pre[j].first));
      }
    }
  }
};


int N;
vector<int> A, B;
int Q;
vector<int> O, I, X, L, R;

int main() {
  for (int numCases; ~scanf("%d", &numCases); ) { for (int caseId = 1; caseId <= numCases; ++caseId) {
    scanf("%d%d", &N, &V);
    A.resize(N); for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
    B.resize(N); for (int i = 0; i < N; ++i) scanf("%d", &B[i]);
    scanf("%d", &Q);
    O.resize(Q);
    I.assign(Q, -1);
    X.assign(Q, -1);
    L.assign(Q, -1);
    R.assign(Q, -1);
    for (int q = 0; q < Q; ++q) {
      scanf("%d", &O[q]);
      if (O[q] == 1) {
        scanf("%d%d", &I[q], &X[q]);
        --I[q];
      } else if (O[q] == 2) {
        scanf("%d%d", &L[q], &R[q]);
        --L[q];
      } else {
        assert(false);
      }
    }
    
    SegmentTreePoint<Node> seg(N);
    for (int i = 0; i < N; ++i) {
      seg.at(i) = Node(A[i], B[i]);
    }
    seg.build();
    
    vector<int> anss;
    for (int q = 0; q < Q; ++q) {
      if (O[q] == 1) {
// cerr<<COLOR("33")<<"change "<<I[q]<<" "<<X[q]<<COLOR()<<endl;
        const int i = I[q];
        seg.change(i, Node(A[i], B[i] = X[q]));
      } else if (O[q] == 2) {
// cerr<<COLOR("33")<<"get "<<L[q]<<" "<<R[q]<<COLOR()<<endl;
        const auto res = seg.get(L[q], R[q]);
        anss.push_back(res.ans);
#ifdef LOCAL
int brt=INF;
for(int i=L[q];i<R[q];++i){
 int a=-INF,b=0;
 for(int j=i;j<R[q];++j){
  chmax(a,A[j]);
  b|=B[j];
  if(b>=V)chmin(brt,a);
 }
}
if(brt!=res.ans){
 cerr<<"V = "<<V<<endl;
 cerr<<"A = "<<A<<endl;
 cerr<<"B = "<<B<<endl;
 cerr<<L[q]<<" "<<R[q]<<": "<<brt<<" "<<res.ans<<endl;
 for(int u=1;u<seg.n<<1;++u)cerr<<"ts["<<u<<"] = "<<seg.ts[u]<<endl;
}
assert(brt==res.ans);
#endif
      } else {
        assert(false);
      }
    }
    
    int ou = 0;
    for (const int ans : anss) {
      if (ou++) printf(" ");
      printf("%d", (ans < INF) ? ans : -1);
    }
    puts("");
  }
#ifndef LOCAL
  break;
#endif
  }
  return 0;
}
