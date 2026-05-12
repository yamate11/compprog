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

  const ll n_alph = 26;
  ll big = 1e18;

  ll N; cin >> N;
  vector S(N, vector<string>());
  REP(i, 0, N) {
    ll k; cin >> k;
    REP(j, 0, k) {
      string s; cin >> s;
      S[i].push_back(s);
    }
  }
  vector P(N, vector<vector<vector<ll>>>());
  REP(i, 0, N) {
    ll szbs = ssize(S[i]);
    P[i] = vector(szbs, vector<vector<ll>>());
    REP(j, 0, szbs) {
      const string& s = S[i][j];
      ll len = ssize(s);
      P[i][j] = vector(len + 1, vector<ll>());
      P[i][j][len] = vector(n_alph, big);
      REPrev(t, len - 1, 0) {
        P[i][j][t] = P[i][j][t + 1];
        P[i][j][t][s[t] - 'a'] = t;
      }
    }
  }


  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    string t; cin >> t;
    ll t_len = ssize(t);
    ll ans = 0;
    REP(i, 0, N) {
      auto is_substr = [&](ll j) -> bool {
        ll pos = P[i][j][0][t[0] - 'a'];
        if (pos == big) return false;
        REP(z, 1, t_len) {
          pos = P[i][j][pos + 1][t[z] - 'a'];
          if (pos == big) return false;
        }
        return true;
      };
      if (EXISTS(j, 0, ssize(S[i]), is_substr(j))) ans++;
    }
    cout << ans << "\n";
  }

  return 0;
}

