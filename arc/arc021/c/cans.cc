#include <bits/stdc++.h>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>
typedef long long int ll;
using namespace std;
using namespace boost::multiprecision;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K, N; cin >> K >> N;
  vector<ll> A(N), D(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i) >> D.at(i);

  auto upto = [&](ll t) -> ll {
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
      if (t < A.at(i)) continue;
      cnt += (t - A.at(i)) / D.at(i) + 1;
    }
    return cnt;
  };

  ll within = 0;
  ll over = 1e12;
  while (within + 1 < over) {
    ll mid = (within + over) / 2;
    if (upto(mid) <= K) within = mid;
    else                over = mid;
  }
  // ll tot = 0;
  cpp_int tot = 0;
  for (ll i = 0; i < N; i++) {
    if (within < A.at(i)) continue;
    ll p = (within - A.at(i)) / D.at(i);
    // tot += (2 * A.at(i) + p * D.at(i)) * (p + 1) / 2;
    tot += ((cpp_int)2 * A.at(i) + (cpp_int)p * D.at(i)) * (p + 1) / 2;
  }
  ll cnt = upto(within);
  cout << tot + over * (K - cnt) << endl;

  return 0;
}

