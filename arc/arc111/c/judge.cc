#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

struct MyExc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N + 1), B(N + 1), P(N + 1);

  auto solve = [&]() -> bool {
    using stb = pair<ll, ll>;
    vector<stb> AI(N + 1);

    for (ll i = 1; i <= N; i++) {
      ll a; cin >> a;
      A[i] = a;
      AI[i] = stb(a, i);
    }
    sort(AI.begin(), AI.end());
    for (ll i = 1; i <= N; i++) cin >> B[i];
    for (ll i = 1; i <= N; i++) {
      ll p; cin >> p;
      P[i] = p;
    }
    for (ll i = 1; i <= N; i++) {
      ll j = P[i];
      if (i != j && B[j] >= A[i]) return false;
    }
    return true;
  };

  auto rep = [&](bool b) -> void {
    if (b) cout << "OK\n";
    else cout << "NG\n";
    throw MyExc();
  };

  bool bs = solve();
  try {
    ll zK; cin >> zK;
    if (zK == -1) rep(bs == false);
    for (ll i = 1; i <= zK; i++) {
      ll p, q; cin >> p >> q;
      if (p == q) rep(false);
      if (B[P[p]] >= A[p]) rep(false);
      if (B[P[q]] >= A[q]) rep(false);
      swap(P[p], P[q]);
    }
    for (ll i = 1; i <= N; i++) {
      if (P[i] != i) rep(false);
    }
    rep(true);
  }catch (const MyExc& e) {
  }

  

  return 0;
}

