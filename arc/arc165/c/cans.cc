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

// @@ !! LIM(binsearch UnionFind ftwo)

// ---- inserted library file binsearch.cc

template<typename T>
T binsearch_i(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / 2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template<typename T>
T binsearch_r(auto check, T yes, T no, T err, bool rel = true) {
  while (abs(yes - no) > err &&
         (!rel || abs(yes - no) > abs(yes) * err)) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc

// ---- inserted library file UnionFind.cc

template<typename T = ll, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {
  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<pair<int, optional<T>>> _leader;
  vector<int> _gsize;
  bool built_groups;
  vector<vector<int>> _groups;
  
  UnionFind(int size_, T zero_ = (T)0, oplus_t oplus_ = plus<T>(), onegate_t onegate_ = negate<T>())
    : size(size_), zero(zero_), oplus(oplus_), onegate(onegate_), _gsize(size, 1), built_groups(false) {
    for (int i = 0; i < size; i++) _leader.emplace_back(i, zero);
  }

  int merge(int i, int j, optional<T> p = nullopt) {
    built_groups = false;
    auto [li, pi] = leaderpot(i);
    auto [lj, pj] = leaderpot(j);
    if (li == lj) {
      if (not p.has_value()) _leader[li].second = nullopt;
      else if (pi.has_value() and oplus(*p, *pj) != *pi) _leader[li].second = nullopt;
      return li;
    }
    int new_leader, obs_leader; bool chg_sign;
    if (_gsize[li] < _gsize[lj]) {
      new_leader = lj;
      obs_leader = li;
      chg_sign = false;
    }else {
      new_leader = li;
      obs_leader = lj;
      chg_sign = true;
    }
    _gsize[new_leader] += _gsize[obs_leader];
    _leader[obs_leader].first = new_leader;
    if (p.has_value() and pi.has_value() and pj.has_value()) {
      T new_pot = oplus(*p, oplus(*pj, onegate(*pi)));
      if (chg_sign) new_pot = onegate(new_pot);
      _leader[obs_leader].second = new_pot;
    }else {
      _leader[new_leader].second = nullopt;  // Note this is for new_leader
    }
    return new_leader;
  }

  pair<int, optional<T>> leaderpot(int i) {
    int cur = i;
    vector<pair<int, optional<T>>> seen;
    optional<T> pp;
    {
      auto [nxt, p] = _leader[cur];
      while (cur != nxt) {
        seen.emplace_back(cur, p);
        cur = nxt;
        tie(nxt, p) = _leader[cur];
      }
      pp = p;
    }
    while (not seen.empty()) {
      auto [j, p] = seen.back(); seen.pop_back();
      if (pp.has_value()) pp = oplus(pp.value(), p.value());
      _leader[j] = {cur, pp};
    }
    return {cur, pp};
  }

  int leader(int i) { return leaderpot(i).first; }
  optional<T> pot(int i) { return leaderpot(i).second; }

  int groupSize(int i) { return _gsize[leader(i)]; }

  const vector<int>& group(int i) {
    if (not built_groups) {
      _groups.resize(size);
      for (int j = 0; j < size; j++) _groups[j].resize(0);
      for (int j = 0; j < size; j++) _groups[leader(j)].push_back(j);
      built_groups = true;
    }
    return _groups[leader(i)];
  }

};

template<typename T = ll>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

// ---- inserted library file ftwo.cc

struct Ftwo {
  int8_t val;

  Ftwo(ll t = 0) { val = t & 1; }
  Ftwo(const Ftwo& t) : val(t.val) {}
  Ftwo& operator =(const Ftwo& t) { val = t.val; return *this; }
  Ftwo& operator =(ll t) { val = (t == 0) ? 0 : 1; return *this; }
  Ftwo& operator =(int t) { val = (t == 0) ? 0 : 1; return *this; }

  Ftwo& operator +=(const Ftwo& t) {
    val ^= t.val;
    return *this;
  }

  Ftwo& operator -=(const Ftwo& t) {
    val ^= t.val;
    return *this;
  }

  Ftwo& operator *=(const Ftwo& t) {
    val &= t.val;
    return *this;
  }

  Ftwo inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    return Ftwo(1);
  }

  Ftwo zero() const { return (Ftwo)0; }
  Ftwo one() const { return (Ftwo)1; }
  Ftwo inverse() const { return inv(); }

  Ftwo& operator /=(const Ftwo& t) {
    return (*this) *= t.inv();
  }

  Ftwo operator +(const Ftwo& t) const { return Ftwo(val) += t; }
  Ftwo operator -(const Ftwo& t) const { return Ftwo(val) -= t; }
  Ftwo operator *(const Ftwo& t) const { return Ftwo(val) *= t; }
  Ftwo operator /(const Ftwo& t) const { return Ftwo(val) /= t; }
  Ftwo operator -() const { return Ftwo(-val); }

  bool operator ==(const Ftwo& t) const { return val == t.val; }
  bool operator !=(const Ftwo& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Ftwo operator +(int x, const Ftwo& y) { return Ftwo(x) + y; }
Ftwo operator -(int x, const Ftwo& y) { return Ftwo(x) - y; }
Ftwo operator *(int x, const Ftwo& y) { return Ftwo(x) * y; }
Ftwo operator /(int x, const Ftwo& y) { return Ftwo(x) / y; }
Ftwo operator +(ll x, const Ftwo& y) { return Ftwo(x) + y; }
Ftwo operator -(ll x, const Ftwo& y) { return Ftwo(x) - y; }
Ftwo operator *(ll x, const Ftwo& y) { return Ftwo(x) * y; }
Ftwo operator /(ll x, const Ftwo& y) { return Ftwo(x) / y; }
Ftwo operator +(const Ftwo& x, int y) { return x + Ftwo(y); }
Ftwo operator -(const Ftwo& x, int y) { return x - Ftwo(y); }
Ftwo operator *(const Ftwo& x, int y) { return x * Ftwo(y); }
Ftwo operator /(const Ftwo& x, int y) { return x / Ftwo(y); }
Ftwo operator +(const Ftwo& x, ll y) { return x + Ftwo(y); }
Ftwo operator -(const Ftwo& x, ll y) { return x - Ftwo(y); }
Ftwo operator *(const Ftwo& x, ll y) { return x * Ftwo(y); }
Ftwo operator /(const Ftwo& x, ll y) { return x / Ftwo(y); }

istream& operator>> (istream& is, Ftwo& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Ftwo& t) {
  os << int(t.val);
  return os;
}

/* 
  From a tweet by Noshibukuro (@noshi91)
  https://twitter.com/noshi91/status/1200702280128856064

  getF2Basis<mode>(vs)  ... Returns a basis of the vector space generated by vs
    mode == 0 ... Returning basis is a subset of vs
    mode == 1 ... Returning basis B is triangular.  I.e., B = {b1, b2, ... } with MSB(b_i) > MSB(b_j) if i < j.
*/
template<int mode>
vector<ll> getF2Basis(const vector<ll>& vs) {
  vector<ll> ret;    // original vectors
  vector<ll> aux;    // This set will also be a basis of the vector space.
  for (ll v : vs) {
    ll e = v;
    for (ll b : aux) { e = min(e, e ^ b); }
    if (e) {
      ret.push_back(v);
      aux.push_back(e);
    }
  }
  if constexpr (mode == 0) return ret;
  else if constexpr (mode == 1) {
    sort(aux.begin(), aux.end(), greater<ll>());
    return aux;
  }else static_assert([]{ return false; }(), "mode must be 0 or 1");
}

// ---- end ftwo.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), W)) [RtF7nzNx]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto W = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; W[i] = v3;
  }
  // @End [RtF7nzNx]

  // auto nbr = vector(N, vector<ll>());
  auto lens = vector(N, vector<ll>());
  REP(i, 0, M) {
    lens[A[i]].push_back(W[i]);
    lens[B[i]].push_back(W[i]);
  }
  REP(i, 0, N) sort(ALL(lens[i]));
  ll min2 = 1e10;
  REP(i, 0, N) if (SIZE(lens[i]) >= 2) min2 = min(min2, lens[i][0] + lens[i][1]);

  auto check = [&](ll X) -> bool {
    UnionFind<Ftwo> uf(N);
    REP(i, 0, M) if (W[i] < X) uf.merge(A[i], B[i], Ftwo(1));
    REP(i, 0, N) if (not uf.pot(i)) return false;
    return true;
  };
  ll X = binsearch_i<ll>(check, 1, min2 + 1);
  cout << X << endl;

  return 0;
}

