#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll ans = 0;
  using StA = pair<ll, ll>;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end(), greater<ll>());
  priority_queue<StA> pque;
  pque.emplace(A.at(1), A.at(0));
  pque.emplace(A.at(1), A.at(0));
  ans = A.at(0);
  for (ll i = 2; i < N; i++) {
    auto [x, y] = pque.top(); pque.pop();
    ans += x;
    pque.emplace(A.at(i), y);
    pque.emplace(A.at(i), x);
  }
  cout << ans << endl;

  return 0;
}

