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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  ll p = N / 2;
  cout << (N - 1) / 2 << endl;
  for (ll i = 0; i < N / 2; i++) {
    if (i > 0) cout << " ";
    cout << A[p] << " " << A[i];
    p++;
  }
  if (N % 2 == 1) cout << " " << A[N - 1];
  cout << endl;


  return 0;
}

