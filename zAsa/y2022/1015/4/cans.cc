#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string S; cin >> S;
  ll N = SIZE(S);
  auto take = [&](ll i) -> pll {
    ll n = 0;
    while (i + 1 < N and S[i] == '2' and S[i + 1] == '5') {
      i += 2;
      n++;
    }
  };

  ll ncnt = 0;
  ll ans = 0;
  for (ll i = 0; true; ) {
    ll ncnt;
    tie(ncnt, i) = take(i);

    if (i + 1 < N and S[i] == '2' and S[i + 1] == '5') {
      ncnt++;
      i += 2;
    }else {
      ans += ncnt * (ncnt + 1) / 2;
      ncnt = 0;
      if (i == N) break;
      i += 1;
    }
  }
  cout << ans << endl;
  return 0;
}

