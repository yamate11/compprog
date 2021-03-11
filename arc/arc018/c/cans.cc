#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  ll N, M; cin >> N >> M;
  ll x_init, A, P; cin >> x_init >> A >> P;
  
  if (A % P == 0) {
    if (x_init < P) return 0;
    return (N - 1) * 2;
  }
  vector<pair<ll, ll>> mark;
  mark.emplace_back(x_init, 0);
  ll m = x_init;
  for (ll i = 1; i < N*M; i++) {
    m = (m + A) % P;
    mark.emplace_back(m, i);
  }
  sort(mark.begin(), mark.end());
  ll cost = 0;
  for (ll r = 0; r < N; r++) {
    vector<ll> vec;
    for (ll c = 0; c < M; c++) {
      ll orig = mark.at(r*M+c).second;
      cost += abs(orig / M - r);
      vec.push_back(orig % M);
    }
    sort(vec.begin(), vec.end());
    for (ll c = 0; c < M; c++) cost += abs(vec.at(c) - c);
  }
  return cost;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  cout << solve() << endl;

  return 0;
}

