#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> exp(N, 0LL);
  for (ll i = 0; i < M; i++) {
    ll a; cin >> a;
    auto check = [&](ll k) -> bool {
      return a > exp.at(k);
    };
    ll j = binsearch<ll>(check, N, -1LL);
    if (j == N) {
      cout << "-1\n";
    }else {
      cout << j+1 << "\n";
      exp.at(j) = a;
    }
  }

  return 0;
}

