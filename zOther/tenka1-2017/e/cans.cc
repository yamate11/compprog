#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(binsearch)
// --> binsearch
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch_i(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / 2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

template<typename T>
T binsearch_r(auto check, T yes, T no, T err, bool rel = true) {
  while (abs(yes - no) > err &&
         (!rel || abs(yes - no) > abs(yes) * err)) {
    T mid = (yes + no) / 2.0;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

ll border_with_hint(ll t, auto pred, auto hint) {
  double y = hint(t);
  double d = floor(y);
  double e = ceil(y);
  bool rd = pred(d, t);
  bool re = pred(e, t);
  if (rd && !re) return d;
  if (!rd && re) return e;
  for (ll i = 1; true; i++) {
    bool rd_i = pred(d - i, t);
    if (rd_i && !rd) return d - i;
    if (!rd_i && rd) return d - (i - 1);
    bool re_i = pred(e + i, t);
    if (re_i && !re) return e + i;
    if (!re_i && re) return e + (i - 1);
  }
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;

  auto dirvec = [](ll a, ll b) -> pair<ll, ll> {
    if (a >= 0) return {-b, a};
    else return {b, -a};
  };

  auto solve1 = [&](const auto& A, const auto& B, const auto& C) -> double {
    using li_t = tuple<ll, ll, ll>;
    vector<li_t> vec;
    for (ll i = 0; i < N; i++) vec.emplace_back(A[i], B[i], C[i]);
    sort(vec.begin(), vec.end(),
         [&](const auto& p, const auto& q) -> bool {
           auto [a1, b1, c1] = p;
           auto [a2, b2, c2] = q;
           auto [u1, v1] = dirvec(a1, b1);
           auto [u2, v2] = dirvec(a2, b2);
           return (u1 * v2 - v1 * u2 > 0);
         });
    auto check = [&](double alpha) -> bool {
      
    };


    return binsearch_r<double>(check, 1e18, -1e18, 1e-9);
    
    
  };

  vector<ll> AA, BB, CC;
  for (ll i = 0; i < N; i++) cin >> AA[i] >> BB[i] >> CC[i];
  double y = solve1(AA, BB, CC);
  double x = solve1(BB, AA, CC);
  cout << x << " " << y << endl;

  return 0;
}

