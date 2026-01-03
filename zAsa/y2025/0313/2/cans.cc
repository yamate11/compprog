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

  ll n; cin >> n;
  // @InpVec(n, a) [uOYPl8Kh]
  auto a = vector(n, ll());
  for (int i = 0; i < n; i++) { ll v; cin >> v; a[i] = v; }
  // @End [uOYPl8Kh]

  ll cnt = 0;
  REP(i, 0, n) {
    while (true) {
      if (a[i] % 2 == 0 or a[i] % 3 == 2) {
        a[i]--;
        cnt++;
      }else break;
    }
  }
  cout << cnt << endl;
  return 0;
}

