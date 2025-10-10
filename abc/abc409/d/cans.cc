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

  auto solve = [&]() -> string {
    ll N; cin >> N;
    string S; cin >> S;

    auto f1 = [&]() -> ll {
      REP(i, 0, N - 1) if (S[i] > S[i + 1]) return i;
      return -1;
    };
    auto f2 = [&](ll a) -> ll {
      REP(i, 1, N) if (S[a] < S[a + i]) return i - 1;
      return N - 1;
    };
    string ret;
    ll a = f1();
    if (a < 0) return S;
    ll b = f2(a);
    ret = S.substr(0, a) + S.substr(a + 1, b) + string(1, S[a]);
    if (a + b + 1 < N) ret += S.substr(a + b + 1);
    return ret;
  };
  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

