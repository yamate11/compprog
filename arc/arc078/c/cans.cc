#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N; cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  ll sum1 = A.at(0);
  ll sum2 = sum - sum1;
  ll ans = abs(sum1 - sum2);
  for (int i = 1; i < N-1; i++) {
    sum1 += A.at(i);
    sum2 -= A.at(i);
    ans = min(ans, abs(sum1 - sum2));
  }
  cout << ans << endl;

  return 0;
}

