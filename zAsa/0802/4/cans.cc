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
  vector<ll> A(N + 1);
  REP(i, 1, N + 1) {
    ll a; cin >> a;
    A[i] = a;
  }
  vector<ll> X(N + 1, 0LL);
  REPrev(i, N, 1) {
    ll s = 0;
    for (ll j = 2 * i; j <= N; j += i) s += X[j];
    if (A[i] != s % 2) {
      X[i] = 1;
    }
  }
  vector<ll> ans;
  REP(i, 1, N + 1) if (X[i]) ans.push_back(i);
  cout << SIZE(ans) << endl;
  REPOUT(i, 0, SIZE(ans), ans[i], " ");


  return 0;
}

