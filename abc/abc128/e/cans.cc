#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 0

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

ll big = (ll)(1e9+100);

struct STNode {
  ll lazy;
  ll vmin;
  STNode() {
    lazy = vmin = big;
  }
};

class SegTree {
private:
  ll tSize;
  vector<STNode> nodes;

  void _update(ll xL, ll xR, ll val, ll node, ll left, ll right) {
    ll& tVmin = nodes.at(node).vmin;
    ll& tLazy = nodes.at(node).lazy;
    if (tLazy <= val) return;
    if (xR <= left || right <= xL)  return;
    tVmin = min(tVmin, val);
    if (xL <= left && right <= xR) {
      tLazy = val;
    }else {
      ll mid = (left + right) / 2;
      _update(xL, xR, val, 2*node+1, left, mid);
      _update(xL, xR, val, 2*node+2, mid, right);
    }
  }

  ll _query(ll xL, ll xR, ll node, ll left, ll right) {
    ll& tVmin = nodes.at(node).vmin;
    ll& tLazy = nodes.at(node).lazy;
    if (xR <= left || right <= xL)  {
      return big;
    }else if (xL <= left && right <= xR) {
      return tVmin;
    }else {
      if (tVmin == tLazy)  return tVmin;
      ll mid = (left + right) / 2;
      ll v1 = _query(xL, xR, 2*node+1, left, mid);
      ll v2 = _query(xL, xR, 2*node+2, mid, right);
      return min(tLazy, min(v1, v2));
    }
  }

public:
  SegTree(ll n) : tSize(n), nodes(4*n) {}

  void update(ll xL, ll xR, ll val) {
    DLOG("update: %lld, %lld, %lld", xL, xR, val);
    return _update(xL, xR, val, 0, 0, tSize);
  }
  
  ll query(ll xL, ll xR) {
    return _query(xL, xR, 0, 0, tSize);
  }

};

ll N, Q;
vector<ll> S, T, X, D;

int main() {
#if !DEBUG
  ios_base::sync_with_stdio(false);
#endif

  cin >> N >> Q;
  S.resize(N);
  T.resize(N);
  X.resize(N);
  for (ll i = 0; i < N; i++) {
    ll s, t, x;
    cin >> s >> t >> x;
    S.at(i) = s;
    T.at(i) = t;
    X.at(i) = x;
  }
  D.resize(Q);
  for (ll i = 0; i < Q; i++) {
    cin >> D.at(i);
  }
  SegTree seg(Q);
  for (ll i = 0; i < N; i++) {
    auto l = lower_bound(D.begin(), D.end(), S.at(i) - X.at(i));
    auto u = upper_bound(D.begin(), D.end(), T.at(i) - X.at(i) - 1);
    seg.update(l - D.begin(), u - D.begin(), X.at(i));
  }
  for (ll i = 0; i < Q; i++) {
    ll v = seg.query(i, i+1);
    cout << (v == big ? -1 : v)  << "\n";
  }

  return 0;
}

