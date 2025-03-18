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
  // @InpVec(N, H) [kGK94UH8]
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; H[i] = v; }
  // @End [kGK94UH8]

  ll ans = 0;
  auto f = [&](auto rF, ll cur, ll st, ll en) -> void {
    ll i = st;
    while (true) {
      while (i < en and H[i] == cur) i++;
      if (i == en) break;
      ll j = i;
      while (j < en and H[j] > cur) j++;
      ans++;
      rF(rF, cur + 1, i, j);
      i = j;
    }
  };

  f(f, 0, 0, N);
  cout << ans << endl;

  return 0;
}

