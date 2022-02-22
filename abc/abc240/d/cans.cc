#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  using sta = pair<ll, ll>;
  vector<sta> stack;
  ll nin = 0;
  REP(i, N) {
    ll a; cin >> a;
    if (stack.empty()) {
      stack.emplace_back(a, 1);
    }else {
      auto [b, n] = stack.back();
      if (b == a) {
        stack.pop_back();
        stack.emplace_back(b, n + 1);
      }else {
        stack.emplace_back(a, 1);
      }
    }
    nin += 1;
    auto [c, m] = stack.back();
    if (c == m) {
      stack.pop_back();
      nin -= m;
    }
    cout << nin << "\n";
  }

  return 0;
}

