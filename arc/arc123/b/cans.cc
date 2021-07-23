#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(binsearch)

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N), B(N), C(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) cin >> B[i];
  for (ll i = 0; i < N; i++) cin >> C[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  ll i = 0;
  ll j = 0;
  ll k = 0;
  for (; i < N; i++) {
    while (j < N && A[i] >= B[j]) j++;
    if (j >= N) break;
    while (k < N && B[j] >= C[k]) k++;
    if (k >= N) break;
    j++; k++;
  }
  cout << i << endl;
  
  /*
  auto check = [&](ll k) -> bool {
    
  };
  ll ans = binsearch_i<ll>(check, 0, N+1);
  */

  return 0;
}

