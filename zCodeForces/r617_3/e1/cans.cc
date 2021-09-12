#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

struct myexc: exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      if (S[i] > S[j]) {
        nbr[i].push_back(j);
        nbr[j].push_back(i);
      }
    }
  }
  vector<ll> A(N, -1);
  auto dfs = [&](auto rF, ll nd, ll col, ll pt) -> void {
    if (A[nd] >= 0) {
      if (A[nd] != col) throw myexc();
      return;
    }
    A[nd] = col;
    for (ll c : nbr[nd]) {
      if (c == pt) continue;
      rF(rF, c, 1 - col, nd);
    }
  };
  try {
    for (ll i = 0; i < N; i++) {
      if (A[i] >= 0) continue;
      dfs(dfs, i, 0, -1);
    }
  }catch(myexc& e) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (ll i = 0; i < N; i++) cout << A[i];
  cout << endl;


  return 0;
}

