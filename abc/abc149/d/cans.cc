#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int N, K; cin >> N >> K;
  int R, S, P; cin >> R >> S >> P;
  string T; cin >> T;
  vector<bool> win(N);
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (i < K || T.at(i - K) != T.at(i) || !win.at(i - K)) {
      if (T.at(i) == 'r') ans += P;
      if (T.at(i) == 's') ans += R;
      if (T.at(i) == 'p') ans += S;
      win.at(i) = true;
    }
  }
  cout << ans << endl;

  return 0;
}

