#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> A(N);
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);
    cnt += A.at(i);
  }
  ll sel = 0;
  for (ll i = 0; i < N; i++) {
    if (4 * M * A.at(i) >= cnt) sel += 1;
  }
  cout << (sel >= M ? "Yes" : "No") << endl;
  

  return 0;
}

