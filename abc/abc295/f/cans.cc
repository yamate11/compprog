#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(digit forall)

// ---- inserted library file digit.cc

struct digit_util {
  ll base;
  vector<ll> _pow;

  digit_util(ll base_ = 10) : base(base_), _pow() {
    ll t = 1;
    while (true) {
      _pow.push_back(t);
      if (__builtin_smulll_overflow(t, base, &t)) break;
    }
  }
    
  ll pow_size() { return _pow.size(); }
  ll pow(ll i) { return _pow[i]; }

  ll width(ll x) {
    if (x <= 0) throw runtime_error("digit.width: x <= 0");
    ll ret = 0;
    for (; x != 0; x /= base) ret++;
    return ret;
  }

  ll nd_min(ll i) { return pow(i - 1); }
  ll nd_max(ll i) { return nd_min(i + 1) - 1; }

  ll floor(ll x) { return (x == 0) ? 0 : _pow[width(x) - 1]; }

  ll ceil(ll x) {
    if (x == 0) return 0;
    ll p = _pow[width(x) - 1];
    return (x == p) ? p : (p * base);
  }

  vector<ll> to_vector(ll x) {
    if (x < 0) throw runtime_error("to_vector: x < 0");
    if (x == 0) return vector<ll>{0};
    vector<ll> ret;
    for ( ; x != 0; x /= base) { ret.push_back(x % base); }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  string to_string(ll x, bool upcase = false) {
    char ten = upcase ? 'A' : 'a';
    string ret;
    for (ll d : to_vector(x)) ret.push_back(d < 10 ? '0' + d : ten + (d - 10));
    return ret;
  }

  ll from_vector(const vector<ll>& vec) {
    ll ret = 0;
    for (ll x : vec) ret = ret * base + x;
    return ret;
  }

  ll from_string(string s) {
    vector<ll> vec;
    for (char c : s) {
      ll x;
      if ('0' <= c and c <= '9')      x = c - '0';
      else if ('a' <= c and c <= 'z') x = c - 'a' + 10;
      else if ('A' <= c and c <= 'Z') x = c - 'A' + 10;
      else throw runtime_error("str_to_ll: unknown letter");
      vec.push_back(x);
    }
    return from_vector(vec);
  }

};

// ---- end digit.cc

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  digit_util du;

  auto solve = [&]() -> ll {
    string _tmp_S; cin >> _tmp_S;
    vector<ll> S;
    for (char c : _tmp_S) S.push_back(c - '0');

    auto f = [&](const auto& upto) -> ll {
      ll max_len = ssize(S) - 1;
      ll max_comp = 16;
      vector tbl_init(2, vector(2, vector(max_comp + 1, vector(max_len + 1, 0LL))));
      auto tbl = tbl_init;
      tbl[1][1][0][0] = 1;

      for (auto d : upto) {
        auto prev = move(tbl);
        tbl = tbl_init;
        REP(eq, 0, 2) REP(az, 0, 2) REP(comp, 0, max_comp + 1) REP(len, 0, max_len + 1) {
          if (prev[eq][az][comp][len] == 0) continue;
          REP(x, 0, 10) {
            if (eq and x > d) continue;
            ll new_eq = eq and x == d;
            ll new_az = az and x == 0;
            auto g = [&]() -> pll {
              ll new_comp = comp;
              if (x == S[len]) {
                if (len == max_len) {
                  new_comp++;
                }else {
                  return pll(new_comp, len + 1);
                }
              }
              if (len > 0) {
                vector<ll> v;
                REP(i, 1, len) v.push_back(S[i]);
                v.push_back(x);
                REPrev(y, len, 1) {
                  if (FORALL(j, 0, y, S[j] == v[(len - y) + j])) {
                    return pll(new_comp, y);
                  }
                }
                return pll(new_comp, 0);
              }else {
                return pll(new_comp, 0);
              }
            };
            auto [new_comp, new_len] = g();
            if (new_az) {
              new_comp = new_len = 0;
            }
            tbl[new_eq][new_az][new_comp][new_len] += prev[eq][az][comp][len];
          }
        }
      }
      ll ret = 0;
      REP(eq, 0, 2) REP(az, 0, 2) REP(comp, 0, max_comp + 1) REP(len, 0, max_len + 1) {
        ret += comp * tbl[eq][az][comp][len];
      }
      return ret;
      
    };

    ll L, R; cin >> L >> R;
    return f(du.to_vector(R)) - f(du.to_vector(L - 1));

  };
  ll T; cin >> T;
  REP(t, 0, T) {
    cout << solve() << "\n";
  }

  return 0;
}

