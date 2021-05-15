#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/convolution>
using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  const ll lim = 1e5;
  vector<ll> vec(lim + 1);
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    vec[a]++;
  }
  auto conved = convolution_ll(vec, vec);
  ll s = 0;
  for (ll i = (ll)conved.size() - 1; i >= 0; i--) {
    if (conved[i] >= M) {
      s += M * i;
      cout << s << endl;
      return 0;
    }
    s += conved[i] * i;
    M -= conved[i];
  }

  return 0;
}

