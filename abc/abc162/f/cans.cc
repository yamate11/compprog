#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  ll M = N % 2 == 0 ? 1 : 2;
  vector<vector<ll>> tbl(N+2, vector<ll>(M+1, LLONG_MIN));
  tbl.at(0).at(0) = 0;
  for (ll i = 0; i < N+2; i++) {
    for (ll j = 0; j <= M; j++) {
      ll cur = tbl.at(i).at(j);
      if (cur == LLONG_MIN) continue;
      if (i+2 < N+2) updMax(tbl.at(i+2).at(j), cur + A.at(i));
      if (i+1 < N+2 && j+1 < M+1) updMax(tbl.at(i+1).at(j+1), cur);
    }
  }
  cout << tbl.at(N+1).at(M) << endl;
  return 0;
}

