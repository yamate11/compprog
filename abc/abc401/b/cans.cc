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
  bool logged_in = false;
  ll ans = 0;
  REP(i, 0, N) {
    string S; cin >> S;
    if (S == "login") {
      logged_in = true;
    }else if (S == "logout") {
      logged_in = false;
    }else if (S == "public") {
    }else if (S == "private") {
      if (not logged_in) ans++;
    }else assert(0);
  }
  cout << ans << endl;

  return 0;
}

