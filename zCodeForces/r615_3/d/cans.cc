#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll q, x; cin >> q >> x;
  vector<ll> rec(x);
  using sta = pair<ll, ll>;
  set<sta> st;
  for (ll i = 0; i < x; i++) st.insert(make_pair(0LL, i));
  for (ll _q = 0; _q < q; _q++) {
    ll a; cin >> a;
    ll b = a % x;
    st.erase(make_pair(rec[b], b));
    rec[b]++;
    st.insert(make_pair(rec[b], b));
    auto [k, j] = *(st.begin());
    cout << k * x + j << "\n";
  }


  return 0;
}

