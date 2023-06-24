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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll lim = 1e5 + 1;
  vector cnt(lim, 0LL);
  REP(i, 0, N) {
    ll a; cin >> a;
    cnt[a]++;
  }
  ll odd = 0, even = 0;
  REP(i, 0, lim) {
    if (cnt[i] == 0) {
    }else if (cnt[i] % 2 == 0) {
      even++;
    }else {
      odd++;
    }
  }
  if (even % 2 == 0) {
    cout << odd + even << endl;
  }else {
    cout << odd + even - 1 << endl;
  }

  return 0;
}

