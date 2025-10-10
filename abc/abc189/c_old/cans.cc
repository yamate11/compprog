#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  auto B(A);
  reverse(B.begin(), B.end());
  auto func = [&N](const auto& vec) -> vector<ll> {
    vector<ll> ret(N);
    using st_t = pair<ll, ll>;
    vector<st_t> st({{-100, -1}});
    for (ll i = 0; i < N; i++) {
      while (true) {
        auto [ht, idx] = st.back();
        if (ht >= vec[i]) {
          st.pop_back();
        }else {
          ret[i] = idx + 1;
          st.emplace_back(vec[i], i);
          break;
        }
      }
    }
    return ret;
  };
  auto left = func(A);
  auto right = func(B);
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll l = left[i];
    ll x = right[N-1 - i];
    ll r = N-1 - x;
    ll s = (r - l + 1) * A[i];
    ans = max(ans, s);
  }
  cout << ans << endl;

  return 0;
}

