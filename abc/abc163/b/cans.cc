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
  ll cnt = 0;
  for (ll i = 0; i < M; i++) {
    ll a; cin >> a;
    cnt += a;
  }
  cout << (cnt > N ? -1 : N - cnt) << endl;

  return 0;
}

