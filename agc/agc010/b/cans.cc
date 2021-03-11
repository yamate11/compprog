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
  vector<ll> A(N), D(N);
  ll t = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    t += A.at(i);
  }
  ll u = N * (N+1) / 2;
  if (t % u != 0) {
    cout << "NO\n";
    return 0;
  }
  ll m = t / u;
  for (int i = 0; i < N-1; i++) D.at(i) = A.at(i + 1) - A.at(i);
  D.at(N-1) = A.at(0) - A.at(N-1);
  for (int i = 0; i < N; i++) {
    ll y = m - D.at(i);
    if (y < 0 || y % N != 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";

  return 0;
}

