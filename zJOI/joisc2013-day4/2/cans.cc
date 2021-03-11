#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N), B(N), C(N), D(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    A[i]--;
  }
  
  vector<bool> visited(N);
  vector<bool> onstack(N);
  // vector<ll> stack;
  ll ans = 0;

  for (ll k = 0; k < N; k++) {
    ll sum = 0;
    bool flag = true;
    ll dmin = LLONG_MAX;

    auto dfs = [&](auto rF, ll i) -> ll {
      if (visited[i]) return -1;
      if (onstack[i]) return i;
      onstack[i] = true;
      ll j = A[i];
      if (visited[i]) {
        sum += max(C[j], D[j]) * B[i];
        return -1;
      }else {
        ll z = rF(rF, j);
        if (z >= 0) {
          if (C[j] >= D[j]) {
            ll val = C[j] * B[i];
            sum += val;
            dmin = min(dmin, B[i] * (C[j] - D[j]));
          }else if (C[j] < D[j]) {
            ll val = D[j] * B[i];
            sum += val;
            dmin = min(dmin, B[i] * (D[j] - C[j]));
            flag = !flag;
          }else assert(0);
          if (z == i) {
            if (!flag) sum -= dmin;
            z = -1;
          }
        }else {
          sum += max(C[j], D[j]) * B[i];
        }
        visited[i] = true;
        return z;
      }
    };
    dfs(dfs, k);
    ans += sum;
  }
  cout << ans << endl;


  return 0;
}

