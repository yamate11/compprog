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

// @@ !! LIM(rle forall)

// ---- inserted library file rle.cc

template<class InputIt, class OutputIt>
OutputIt rle_iter(InputIt first, InputIt last, OutputIt d_first) {
  InputIt itA = first;
  OutputIt oit = d_first;
  while (itA != last) {
    InputIt itB = next(itA);
    for (; itB != last and *itA == *itB; itB++);
    *oit = make_pair(*itA, itB - itA);
    itA = itB;
    oit++;
  }
  return oit;
}

template<class V>
auto rle(V vec) {
  vector<pair<typename V::value_type, ll>> ret;
  rle_iter(vec.begin(), vec.end(), back_inserter(ret));
  return ret;
}

// ---- end rle.cc

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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    string X, Y; cin >> X >> Y;

    auto check = [&](ll start, ll end) -> bool {
      ll nAY = 0, nBY = 0, nAX = 0, nBX = 0, nCX = 0;
      REP(i, start, end) {
        if (X[i] == 'A') nAX++;
        else if (X[i] == 'B') nBX++;
        else if (X[i] == 'C') nCX++;
        else assert(0);
        if (Y[i] == 'A') nAY++;
        else if (Y[i] == 'B') nBY++;
        else assert(0);
      }
      if (nAX + nCX < nAY) return false;
      if (nBX + nCX < nBY) return false;
      ll kA = nAY - nAX;
      ll kB = nBY - nBX;
      assert(kA + kB == nCX and kA >= 0 and kB >= 0);
      REP(i, start, end) {
        if (X[i] == 'C') {
          if (kA > 0) {
            X[i] = 'A';
            kA--;
          }else {
            X[i] = 'B';
            kB--;
          }
        }
      }
      assert(kA == 0 and kB == 0);
      ll cntX = 0, cntY = 0;
      REP(i, start, end) {
        if (X[i] == 'A') cntX++;
        if (Y[i] == 'A') cntY++;
        if (cntY > cntX) return false;
      }
      return true;
      
    };

    string Z = Y;
    REP(i, 0, N) if (Z[i] == 'B') Z[i] = 'A';
    ll pos = 0;
    for (auto [c, len] : rle(Z)) {
      if (c == 'A') {
        if (not check(pos, pos + len)) return false;
      }else {
        if (EXISTS(i, pos, pos + len, X[i] != 'C')) return false;
      }
      pos += len;
    }
    return true;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

