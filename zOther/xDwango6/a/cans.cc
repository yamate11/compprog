#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<string> S(N);
  vector<ll> T(N);
  for (ll i = 0; i < N; i++) cin >> S.at(i) >> T.at(i);
  string X; cin >> X;
  ll cnt = 0;
  bool sl = false;
  for (ll i = 0; i < N; i++) {
    if (sl) {
      cnt += T.at(i);
    }else if (S.at(i) == X) {
      sl = true;
    }
  }
  cout << cnt << endl;

  return 0;
}

