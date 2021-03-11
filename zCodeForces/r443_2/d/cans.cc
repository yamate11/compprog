#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {

    ll n, k, m; cin >> n >> k >> m;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) cin >> A[i];
    auto rem_seq = [&k](vector<ll>& vec) -> vector<ll> {
      vector<pair<ll, ll>> cnt{{-1, 0}};
      for (ll i = 0; i < (ll)vec.size(); i++) {
        auto& [x, c] = cnt.back();
        if (vec[i] != x)   cnt.emplace_back(vec[i], 1);
        else if (++c == k) cnt.pop_back();
      }
      vector<ll> ret;
      for (auto [x, c] : cnt) {
        if (x < 0) continue;
        for (ll i = 0; i < c; i++) ret.push_back(x);
      }
      return ret;
    };
    vector<ll> B = rem_seq(A);
    if (m == 1 || B.size() == 0) return B.size();
    auto uniq_col = [](const auto& v, ll p, ll q) {
      for (ll i = p; i < q; i++) if (v[i] != v[p]) return false;
      return true;
    };
    if (uniq_col(B, 0, B.size())) return (B.size() * m) % k;
    vector<ll> C(B.size() * 2);
    copy(B.begin(), B.end(), C.begin());
    copy(B.begin(), B.end(), C.begin() + B.size());
    vector<ll> D = rem_seq(C);
    if (D.size() == 0) return m % 2 == 0 ? 0 : B.size();
    ll p = 0;
    for (; p < (ll)D.size() && p < (ll)B.size() && D[p] == B[p]; p++);
    ll r = D.size() - B.size();
    ll q = B.size() - p - r;
    if (!uniq_col(B, p, p + r)) return p + m * r + q;
    ll rem = m * r % k;
    if (rem > 0) return p + rem + q;
    copy(D.end() - q, D.end(), D.begin() + p);
    D.resize(p + q);
    auto E = rem_seq(D);
    return E.size();
  };

  cout << solve() << endl;
  return 0;
}

