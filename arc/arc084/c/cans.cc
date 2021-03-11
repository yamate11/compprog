#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N), B(N), C(N), BC(N), ABC(N), s(N+1), t(N+1);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  for (ll i = 0; i < N; i++) cin >> B.at(i);
  for (ll i = 0; i < N; i++) cin >> C.at(i);
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  ll j = 0;
  for (ll i = 0; i < N; i++) {
    while (j < N && C.at(j) <= B.at(i)) j++;
    BC.at(i) = N - j;
  }

  s.at(N) = 0;
  for (ll i = N-1; i >= 0; i--) s.at(i) = s.at(i+1) + BC.at(i);

  t.at(N) = 0;
  for (ll i = N-1; i >= 0; i--) t.at(i) = t.at(i+1) + s.at(i);

  ll ans = 0;
  j = 0;
  for (ll i = 0; i < N; i++) {
    while (j < N && B.at(j) <= A.at(i)) j++;
    ans += s.at(j);
  }
  cout << ans << endl;

  return 0;
}

