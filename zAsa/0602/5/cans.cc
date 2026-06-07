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

  auto ask = [&](ll i, ll j) -> ll {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    ll x;
    cin >> x;
    return x;
  };
  auto report = [&](ll x) -> void {
    cout << "! " << x << endl;
  };

  ll N; cin >> N;
  vector<ll> A(N);
  REP(i, 1, N) {
    A[i] = ask(0, i);
  }
  ll i0 = ranges::max_element(A) - A.begin();
  vector<ll> B(N);
  REP(i, 0, N) {
    if (i != i0) B[i] = ask(i0, i);
  }
  ll ans = *ranges::max_element(B);
  report(ans);

  return 0;
}

