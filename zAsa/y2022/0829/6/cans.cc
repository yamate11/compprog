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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

void solve() {
  ll N; cin >> N;
  vector<ll> H(N); REP(i, 0, N) cin >> H[i];
  vector<ll> stack;
  stack.push_back((ll)1e9);
  REP(i, 0, N) {
    cout << SIZE(stack) - 1 << "\n";
    while (stack.back() < H[i]) stack.pop_back();
    stack.push_back(H[i]);
  }
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  solve();

  return 0;
}

