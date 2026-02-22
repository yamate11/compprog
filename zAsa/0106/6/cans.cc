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
  vector<ll> vec(N);
  REP(i, 0, N) cin >> vec[i];

  auto f = [&](auto rF, ll st) -> pll {
    ll subval = 0;
    ll i = st + 1;
    ll exp = 2;
    while (i < N) {
      if (vec[i] == 1) {
        auto [v, ni] = rF(rF, i);
        subval += v;
        i = ni;
      }else if (vec[i] ==exp) {
        exp++;
        i++;
      }else break;
    }
    return pll(i - st + subval, i);
  };

  ll ans = 0;
  ll i = 0;
  while (i < N) {
    while (i < N and vec[i] != 1) i++;
    if (i == N) break;
    auto [val, new_i] = f(f, i);
    ans += val;
    i = new_i;
  }
  cout << ans << endl;
  return 0;
}

