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
    ll R, N, M, L; cin >> R >> N >> M >> L;
    // @InpVec(L, S) [pitK5jQf]
    auto S = vector(L, ll());
    for (int i = 0; i < L; i++) { ll v; cin >> v; S[i] = v; }
    // @End [pitK5jQf]

    auto f = [&](ll pos) -> ll {
      ll cnt = 0;
      REP(i, 0, M) {
        if (pos + i >= L) return -1;
        cnt += S[pos + i];
        if (cnt > N) return -1;
        if (cnt == N) return pos + i + 1;
      }
      return pos + M;
    };

    ll pos = 0;
    REP(i, 0, R) {
      pos = f(pos);
      if (pos < 0) return false;
    }
    return pos == L;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

