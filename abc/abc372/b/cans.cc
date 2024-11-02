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

  ll M; cin >> M;
  vector<ll> ans;
  ll c = 0;
  while (M > 0) {
    ll x = M % 3;
    if (x == 1) ans.push_back(c);
    else if (x == 2) {
      ans.push_back(c);
      ans.push_back(c);
    }
    M = M / 3;
    c++;
  }
  cout << ssize(ans) << "\n";
  for (ll a : ans) {
    cout << a << " ";
  }
  cout << "\n";

  return 0;
}

