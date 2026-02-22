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
  // @InpVec(N, A) [qU70aZK7]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [qU70aZK7]
  ranges::sort(A);
  
  ll t = N;

  vector<ll> ans;
  ll carry = 0;
  ll j = 0;
  REP(i, 0, N) {
    for (; j < A[i]; j++) {
      ll x = (t + carry) % 10;
      ans.push_back(x);
      carry = (t + carry) / 10;
    }
    t--;
  }
  while (carry > 0) {
    ll x = carry % 10;
    ans.push_back(x);
    carry = carry / 10;
  }

  ranges::reverse(ans);
  REPOUT(i, 0, ssize(ans), ans[i], "");

  return 0;
}

