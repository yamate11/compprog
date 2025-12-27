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

// @@ !! LIM(forall)

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

  ll N, M, Q; cin >> N >> M >> Q;

  auto ask = [&](ll x, ll y) -> ll {
    cout << "? " << x << " " << y << endl;
    ll z; cin >> z;
    return z;
  };

  auto f = [&](auto rF, const auto& V, ll m) -> vector<ll> {
    vector<ll> f_ret(ssize(V));
    vector<ll> res(ssize(V) / 2);
    vector<ll> same_pos;
    vector<ll> diff_pos;
    REP(i, 0, ssize(V) / 2) {
      res[i] = ask(V[2*i], V[2*i + 1]);
      if      (res[i] == 0) same_pos.push_back(i);
      else if (res[i] == 1) diff_pos.push_back(i);
      else assert(0);
    }
    ll m_rem = m - ssize(diff_pos);
    ll corr = -1;
    if (m_rem > 0) {
      if (m_rem % 2 != 0) {
        assert(ssize(V) % 2 != 0);
        f_ret.back() = 1;
      }
      vector<ll> W;
      for (ll i : same_pos) W.push_back(V[2 * i]);
      auto S = rF(rF, W, m_rem / 2);
      REP(j, 0, ssize(same_pos)) {
        ll i = same_pos[j];
        f_ret[2 * i] = f_ret[2 * i + 1] = S[j];
        if (S[j] == 0) corr = V[2 * i];
      }
    }else {
      REP(j, 0, ssize(same_pos)) {
        ll i = same_pos[j];
        f_ret[2 * i] = f_ret[2 * i + 1] = 0;
      }
      corr = V[2 * same_pos[0]];
    }
    for (ll i : diff_pos) {
      ll r = ask(V[2 * i], corr);
      if      (r == 0) { f_ret[2 * i] = 0; f_ret[2 * i + 1] = 1; }
      else if (r == 1) { f_ret[2 * i] = 1; f_ret[2 * i + 1] = 0; }
      else assert(0);
    }
    return f_ret;
  };

  vector<ll> vec0(N);
  REP(i, 0, N) vec0[i] = i + 1;
  auto ans = f(f, vec0, M);

  cout << "!";
  REP(i, 0, N) if (ans[i]) cout << " " << i + 1;
  cout << endl;
  return 0;
}

