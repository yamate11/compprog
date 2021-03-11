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
  vector<ll> A(N), S(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  ll s = 0;
  for (int i = 0; i < N; i++) {
    s += A.at(i);
    S.at(i) = s;
  }
  int i = N - 2;
  for (; i >= 0; i--) {
    if (S.at(i) * 2LL < A.at(i+1)) break;
  }
  cout << N - 1 - i << endl;
  
  return 0;
}

