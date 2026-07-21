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

  auto ask = [&](ll i, ll j) -> bool {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    string s; cin >> s;
    if (s == "Yes") return true;
    else return false;
  };
  auto rep = [&](ll a) -> void {
    cout << "! " << a << endl;
    return;
  };

  ll N; cin >> N;
  ll j = 1;
  ll ans = 0;
  REP(i, 0, N) {
    if (i == j) j++;
    while (true) {
      if (j == N) {
        ans += N - i - 1;
        break;
      }else if (not ask(i, j)) {
        ans += j - i - 1;
        break;
      }
      j++;
    }
  }
  rep(ans);
  return 0;
}

