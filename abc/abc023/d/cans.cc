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

  ll N; cin >> N;
  vector H(N, 0LL), S(N, 0LL);
  for (ll i = 0; i < N; i++) {
    cin >> H.at(i) >> S.at(i);
  }
  auto check = [&](ll ht) -> bool {
    vector tl(N, 0LL);
    for (ll i = 0; i < N; i++) {
      if (ht < H.at(i)) tl.at(i) = -1;
      else              tl.at(i) = max(0LL, (ht - H.at(i)) / S.at(i));
    }
    sort(tl.begin(), tl.end());
    for (ll i = 0; i < N; i++) {
      if (tl.at(i) < i) return false;
    }
    return true;
  };

  ll x = binsearch<ll>(check, ll(1e16), 0LL);
  cout << x << endl;

  return 0;
}

