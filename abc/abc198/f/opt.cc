#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep_(i, a_, b_, a, b, ...) for (int i = (a), lim##i = (b); i < lim##i; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
using ll = long long;
using Rot = array<int, 6>;
using mint = modint998244353;


// 24 個の置換を BFS で生成
set<Rot> gen_perm() {
  const Rot e = {0, 1, 2, 3, 4, 5};
  const vector<Rot> ps = {
    {0, 2, 3, 4, 1, 5}, // 1234
    {1, 5, 2, 0, 4, 3}, // 0153
  };
  queue<Rot> que;
  set<Rot> S;
  que.push(e); S.insert(e);
  while (!que.empty()) {
    auto p = que.front(); que.pop();
    for (auto q : ps) {
      rep(i, 6) q[i] = p[q[i]];
      if (S.count(q)) continue;
      que.push(q); S.insert(q);
    }
  }
  return S;
}


// 有理式 p(x) / q(x) で表される形式的冪級数の x^n の係数を計算
template<class T>
struct bostan_mori {
  vector<T> p, q;
  bostan_mori(vector<T> &_p, vector<T> &_q) : p(_p), q(_q) {}
  void rev(vector<T> &f) const {
    int d = f.size();
    rep(i, d) if (i&1) f[i] = -f[i];
  }
  void even(vector<T> &f) const {
    int d = (f.size() + 1) >> 1;
    rep(i, d) f[i] = f[i<<1];
    f.resize(d);
  }
  void odd(vector<T> &f) const {
    int d = f.size() >> 1;
    rep(i, d) f[i] = f[i<<1|1];
    f.resize(d);
  }
  T operator[] (ll n) const {
    vector<T> _p(p), _q(q), _q_rev(q);
    rev(_q_rev);
    for (; n; n >>= 1) {
      _p = convolution(move(_p), _q_rev);
      if (n&1) odd(_p);
      else     even(_p);
      _q = convolution(move(_q), move(_q_rev));
      even(_q);
      _q_rev = _q; rev(_q_rev);
    }
    return _p[0] / _q[0];
  }
};


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

ostream& operator<< (ostream& os, mint x) {
  os << x.val();
  return os;
}


// 方程式
// cs[0] x_0 + cs[1] x_1 + ... + cs[k-1] x_{k-1} = s
// の非負整数解 (x_0, ..., x_{k-1}) の個数を計算
mint subcount(vector<int> cs, ll s) {
  vector<mint> p{1}, q{1};
  for (auto &c : cs) {
    vector<mint> f(c+1);
    f[0] = 1, f[c] = -1;
    q = convolution(q, f);
  }
  bostan_mori<mint> bm(p, q);
  mint v = bm[s];
  cerr << cs << " " << v << endl;
  return v;
}


int main() {
  ll s; cin >> s;
  mint ans = 0;
  auto S = gen_perm();

  for (auto &p : S) {
    dsu uf(6);
    rep(i, 6) uf.merge(i, p[i]);
    vector<int> c;
    for (auto &v : uf.groups()) c.push_back(v.size());
    ans += subcount(c, s-6);
  }
  ans /= S.size();

  cout << ans.val() << '\n';
}
