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

  string S; cin >> S;
  ll N = ssize(S);
  vector<pll> ans;
  ll i = 0;
  while (i < N) {
    while (i < N and S[i] == '.') i++;
    if (i == N) break;
    ll j0 = i;
    i++;
    while (i < N and S[i] == '.') i++;
    assert(i != N);
    ans.emplace_back(j0, i);
    i++;
  }
  for (auto [j, k] : ans) {
    cout << j + 1 << "," << k + 1 << "\n";
  }
  return 0;
}

