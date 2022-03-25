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

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    bool alldiff = true;
    auto foo = [&](auto& v) -> map<ll, ll> {
      map<ll, ll> mp;
      for (ll x : v) {
        if (mp[x] != 0) alldiff = false;
        mp[x]++;
      }
      return mp;
    };
    auto mpA = foo(A);
    auto mpB = foo(B);
    for (auto [x, c] : mpA) if (mpB[x] != c) return false;
    if (not alldiff) return true;
    auto func = [&](auto& v) -> ll {
      ll cnt = 0;
      REP(i, N) REP2(j, i + 1, N) if (v[i] > v[j]) cnt++;
      return cnt;
    };
    ll x = func(A);
    ll y = func(B);
    return (x - y) % 2 == 0;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

