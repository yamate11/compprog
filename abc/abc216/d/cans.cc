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

  ll N, M; cin >> N >> M;
  vector<vector<ll>> A(M);
  vector<vector<ll>> tops(2, vector<ll>(N, -1));
  for (ll i = 0; i < M; i++) {
    ll k; cin >> k;
    A[i].resize(k);
    for (ll j = 0; j < k; j++) {
      ll a; cin >> a; a--;
      A[i][k - j - 1] = a;
    }
  }
  vector<ll> cand;
  auto put = [&](ll x, ll i) -> void {
    if (tops[0][x] < 0) {
      tops[0][x] = i;
    }else {
      tops[1][x] = i;
      cand.push_back(x);
    }
  };
  for (ll i = 0; i < M; i++) {
    if (! A[i].empty()) {
      ll x = A[i].back();
      put(x, i);
    }
  }
  ll done = 0;
  while (! cand.empty()) {
    ll x = cand.back(); cand.pop_back();
    ll i = tops[0][x];
    ll j = tops[1][x];
    A[i].pop_back();
    if (! A[i].empty()) {
      ll y = A[i].back();
      put(y, i);
    }
    A[j].pop_back();
    if (! A[j].empty()) {
      ll y = A[j].back();
      put(y, j);
    }
    done++;
  }
  if (done == N) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

