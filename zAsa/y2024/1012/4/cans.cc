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
  // @InpVec(N, A) [TPopcfTA]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [TPopcfTA]

  set<ll> ss;
  {
    ll x = 2e9;
    REP(i, 0, N) {
      ll a = A[i];
      if (ss.contains(a)) {
        ss.insert(x++);
      }else {
        ss.insert(a);
      }
    }
  }
  vector<ll> vec;
  for (ll a : ss) vec.push_back(a);
  ll i = 0, j = N - 1;
  ll x = 1;
  while (i <= j) {
    if (x < vec[i]) {
      if (i <= j - 1) {
        x++;
        j -= 2;
      }else {
        break;
      }
    }else {
      x++;
      i++;
    }
  }
  cout << x - 1 << endl;

  return 0;
}

