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

  ll n = 1e7;
  vector<ll> vec(n);
  ll j = 0;
  ll k; cin >> k;
  if (k % 2 == 0) {
    REP(i, 0, 20*n) {
      vec[0] = j;
      j += k;
      if (j > n) j -= n;
    }
  }else {
    REP(i, 0, 20*n) {
      vec[j] = j;
      j += k;
      if (j > n) j -= n;
    }
  }

  return 0;
}

