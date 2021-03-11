#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  ll N, C; cin >> N >> C;
  vector<ll> even(11), odd(11);
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (i % 2 == 0) even.at(a)++;
    else            odd.at(a)++;
  }
  auto check = [&](const auto& vec, ll num, ll& nFst, ll& nC, ll& nSnd) {
    vector<pair<ll, ll>> v;
    for (ll i = 1; i <= 10; i++) v.emplace_back(vec.at(i), i);
    sort(v.begin(), v.end(), greater<pair<ll,ll>>());
    nFst = num - v.at(0).first;
    nC = v.at(0).second;
    nSnd = num - v.at(1).first;
  };

  ll eN, et, eM, oN, ot, oM;
  check(even, (N + 1) / 2, eN, et, eM);
  check(odd, N / 2, oN, ot, oM);
  if (et != ot) return C * (eN + oN);
  return C * min(eN + oM, eM + oN);
}  

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

