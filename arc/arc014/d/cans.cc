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

  ll A, N, M; cin >> A >> N >> M;
  vector<ll> L(N);
  vector<ll> gap(N-1);
  for (ll i = 0; i < N; i++) {
    cin >> L.at(i);
    if (i > 0) gap.at(i-1) = L.at(i) - L.at(i-1) - 1;
  }
  sort(gap.begin(), gap.end());
  vector<ll> acc(N);
  for (ll i = 0; i < N-1; i++) acc.at(i+1) = acc.at(i) + gap.at(i);
  for (ll i = 0; i < M; i++) {
    ll X, Y; cin >> X >> Y;
    auto check = [&](ll j) -> bool { return gap.at(j) > X + Y; };
    ll lim = binsearch<ll>(check, N-1, -1);
    ll ans =
      acc.at(lim) + (N-1 - lim) * (X+Y) + N
      + min(X, L.at(0) - 1) + min(Y, A - L.at(N-1));
    cout << ans << "\n";
  }

  return 0;
}

