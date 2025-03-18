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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll K; cin >> K;
    string S, T; cin >> S >> T;
    ll ns = ssize(S);
    ll nt = ssize(T);

    /*
      auto mktbl = [&](string U) {
      ll m = ssize(U);
      vector ret(m, vector<ll>());
      vector<ll> tbl(26, -1LL);
      REPrev(i, m - 1, 0) {
      ll d = U[i] - 'a';
      ret[i] = tbl;
      tbl[d] = i;
      }
      return ret;
      };

      auto tblS = mktbl(S);
      auto tblT = mktbl(T);
    */

    using sta = pair<ll, pll>;
    deque<sta> deq;
    deq.emplace_back(0, pll(0, 0));
    map<pll, ll> mp;
    mp[pll(0, 0)] = 0;
    while (not deq.empty()) {
      auto [d, p] = deq.front(); deq.pop_front();
      if (mp[p] == d) {
        auto [i0, j0] = p;
        if (i0 == ns and j0 == nt) return true;
        else if (i0 == ns) {
          if (d + nt - j0 <= K) return true;
        }else if (j0 == nt) {
          if (d + ns - i0 <= K) return true;
        }else if (S[i0] == T[j0]) {
          pll pp = pll(i0 + 1, j0 + 1);
          auto it = mp.find(pp);
          if (it == mp.end() or d < it->second) {
            mp[pp] = d;
            deq.emplace_front(d, pp);
          }
        }else if (d + 1 <= K) {
          auto sub = [&](pll pp) -> void {
            auto it = mp.find(pp);
            if (it == mp.end() or d < it->second) {
              mp[pp] = d + 1;
              deq.emplace_back(d + 1, pp);
            }
          };
          sub(pll(i0 + 1, j0 + 1));
          sub(pll(i0, j0 + 1));
          sub(pll(i0 + 1, j0));
        }
      }
    }
    return false;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

