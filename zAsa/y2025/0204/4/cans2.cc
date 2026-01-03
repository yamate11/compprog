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

int main() {
  ll N; cin >> N;
  vector<ll> vec(N + 1);
  for (int i = 1; i <= N; i++) for (int j = i; j <= N; j+= i) vec[j]++;
  ll ans = 0;
  for (int i = 1; i <= N; i++) ans += i * vec[i];
  cout << ans << endl;
  return 0;
}

