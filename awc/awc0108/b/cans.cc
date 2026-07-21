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

  ll N; cin >> N;
  // @InpVec(N, S, type=string) [Lg4Qx6tE]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [Lg4Qx6tE]

  string t0 = "sayounara";
  auto check = [&](string s) -> bool {
    ll idx = 0;
    REP(i, 0, ssize(t0)) {
      while (idx < ssize(s) and s[idx] != t0[i]) idx++;
      if (idx == ssize(s)) return false;
      idx++;
    }
    return true;
  };

  REP(i, 0, N) {
    cout << (check(S[i]) ? "Yes\n" : "No\n");
  }

  return 0;
}

