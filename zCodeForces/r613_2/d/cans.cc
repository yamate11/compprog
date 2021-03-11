#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll m0 = 30;

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];

  auto func = [&](auto rF, ll m, const vector<ll>& vec) -> ll {
    if (m == -1) return 0;
    if (vec.empty()) return 0;

    vector<ll> vec0, vec1;
    for (ll x : vec) {
      if ((x >> m) & 1) vec1.push_back(x ^ (1LL << m));
      else              vec0.push_back(x);
    }
    ll t0 = rF(rF, m - 1, vec0);
    ll t1 = rF(rF, m - 1, vec1);
    if (vec0.empty()) return t1;
    if (vec1.empty()) return t0;
    ll t = min(t0, t1);
    return (1LL << m) + t;
  };


  ll x = func(func, m0, A);
  cout << x << endl;



  return 0;
}

