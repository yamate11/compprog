#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, K; cin >> N >> M >> K;
  if (K > 4 * N * M - 2 * N - 2 * M) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  using sta = pair<ll, string>;
  vector<sta> rec;
  ll rem = K;

  auto doit = [&](ll maxtry, string s) -> void {
    if (rem <= 0) return;
    ll k = s.size();
    ll x = rem / k;
    ll t = min(maxtry, x);
    if (t == 0) return;
    rec.emplace_back(t, s);
    rem -= k * t;
    if (rem <= 0) return;
    if (t < maxtry) {
      assert(rem < k);
      rec.emplace_back(1, s.substr(0, rem));
      rem = 0;
    }
  }

  for (ll j = 0; j < N; j++) {
    doit(M-1, "R");
    if (j < N-1) {
      doit(M-1, "DUL");
      doit(1, "D");
    }else {
      doit(M-1, "L");
    }
    doit(1, "U");
  }

  cout << rec.size() << "\n";
  for (auto [t, s] : rec) {
    cout << t << " " << s << "\n";
  }

  return 0;
}

