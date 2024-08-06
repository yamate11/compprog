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

// @@ !! LIM(f:shortVector forall)

// ---- inserted function f:shortVector from util.cc

// Vector for small integers such as 0..3, fit in a small bit width,
// represented with a long long int.
//   - val should be in [0, 1LL << bit_width)
//   - index should be in [0, 1LL << (64 / bit_width))

// bit_width, short_vector, index, value
void sv_set(int bw, ll& sv, int idx, int val) {
  ll mask = (1LL << bw) - 1;
  sv = sv & ~(mask << (idx * bw));
  sv = sv | (val << (idx * bw));
}

ll sv_get(int bw, ll sv, int idx) {
  ll mask = (1LL << bw) - 1;
  return (sv >> (idx * bw)) & mask;
}

string sv_show(int bw, ll sv, ll len = -1) {
  ll mask = (1LL << bw) - 1;
  ll bnd = len < 0 ? 64 : len;
  string ret = "[";
  for (ll i = 0; i < bnd; i++) {
    if (len < 0 && sv == 0) break;
    if (i > 0) ret += ", ";
    ret += to_string(sv & mask);
    sv >>= bw;
  }
  ret += "]";
  return ret;
}
// ---- end f:shortVector

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

  ll N; cin >> N;
  string S, T; cin >> S >> T;
  ll start = 0;
  ll goal = 0;
  REP(i, 0, N) {
    if (S[i] == 'B') sv_set(2, start, i, 1);
    else if (S[i] == 'W') sv_set(2, start, i, 2);
    if (T[i] == 'B') sv_set(2, goal, i, 1);
    else if (T[i] == 'W') sv_set(2, goal, i, 2);
  }
  sv_set(2, start, N, 3);
  sv_set(2, start, N + 1, 3);
  sv_set(2, goal, N, 3);
  sv_set(2, goal, N + 1, 3);

  unordered_map<ll, ll> dist;
  queue<ll> que;
  dist[start] = 0;
  que.push(start);
  while (not que.empty()) {
    ll x = que.front(); que.pop();
    int blank = EXFIND(i, 0, N + 2, sv_get(2, x, i) == 3);
    REP(i, 0, N + 1) {
      if (i + 1 != blank and i != blank and blank + 1 != i) {
        ll y = x;
        sv_set(2, y, blank, sv_get(2, y, i));
        sv_set(2, y, blank + 1, sv_get(2, y, i + 1));
        sv_set(2, y, i, 3);
        sv_set(2, y, i + 1, 3);
        if (not dist.contains(y)) {
          dist[y] = dist[x] + 1;
          if (y == goal) {
            cout << dist[y] << endl;
            return 0;
          }
          que.push(y);
        }
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

