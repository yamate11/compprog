#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;
  bool flip = false;
  ll Q; cin >> Q;
  auto foo = [&](ll x) -> ll {
    if (x < N) return x + N;
    else return x - N;
  };
  for (ll _q = 0; _q < Q; _q++) {
    ll t, a, b; cin >> t >> a >> b; a--; b--;
    if (t == 1) {
      if (flip) {
        a = foo(a);
        b = foo(b);
      }
      char ca = S[a];
      char cb = S[b];
      S[a] = cb;
      S[b] = ca;
    }else if (t == 2) {
      flip = !flip;
    }
  }
  if (flip) {
    cout << S.substr(N, N) << S.substr(0, N) << endl;
  }else {
    cout << S << endl;
  }


  return 0;
}

