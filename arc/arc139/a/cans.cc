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
  vector<ll> T(N); REP(i, N) cin >> T[i];
  auto func = [&](ll a, ll t) {
    ll x = 1LL << t;
    ll mask = (1LL << (t + 1)) - 1;
    ll b = a & (~mask);
    ll c = b + (1LL << (t + 1));
    if ((a & mask) < x) return  b | x;
    else return c | x;
  };
  ll a = 0;
  REP(i, N) {
    a = func(a, T[i]);
  }
  cout << a << endl;

  return 0;
}

