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

  ll t; cin >> t;
  ll N; cin >> N;
  ll x = (N - 1) / t;
  ll y = (N - 1) % t;
  vector<bool> A(100 + t + 1, true);
  REP(i, 1, 101) {
    ll p = (100 + t) * i / 100;
    A[p] = false;
  }
  ll p = 0;
  REP(i, 1, 100 + t + 1) {
    if (A[i]) {
      if (p == y) {
        cout << (100 + t) * x + i << endl;
        return 0;
      }
      p++;
    }
  }
  

  return 0;
}

