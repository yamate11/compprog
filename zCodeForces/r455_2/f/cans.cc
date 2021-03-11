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
  ll b = 1;
  while ((b * 2) <= N) b *= 2;
  vector<ll> res(N + 1);
  if (N % 2 == 1) {
    cout << "NO\n";
  }else {
    cout << "YES\n";
    auto func = [&](auto rF, ll x) -> void {
      if (x == 0) return;
      ll c = 1;
      while ((c * 2) <= x) c *= 2;
      if (c == x) {
        for (ll i = 1; i < x; i++) res[i] = c - 1 - i;
        res[x - 1] = x;
        res[x] = x - 1;
      }else {
        ll y = c * 2 - 1 - x - 1;
        rF(rF, y);
        for (ll i = y + 1; i <= x; i++) res[i] = c * 2 - 1 - i;
      };
    };
    func(func, N);
    for (ll i = 1; i <= N; i++) {
      if (i > 1) cout << " ";
      cout << res[i];
    }
    cout << endl;

  }
  if (N <= 5 || N == b) {
    cout << "NO\n";
  }else {
    cout << "YES\n";
    vector<ll> ans6({0,3,6,2,5,1,4});
    vector<ll> ans7({0,3,7,2,5,1,4,6});
    auto func = [&](auto rF, ll p) -> void {
      if (p == 8) {
        copy(ans7.begin(), ans7.end(), res.begin());
      }else {
        rF(rF, p / 2);
        res[p/2] = p - 1;
        for (ll i = p/2 + 1; i < p; i++) res[i] = i - 1;
      }

    };
    if (N == 6) {
      copy(ans6.begin(), ans6.end(), res.begin());
    }else if (N == 7) {
      copy(ans7.begin(), ans7.end(), res.begin());
    }else {
      func(func, b);
      res[b] = N;
      for (ll i = b + 1; i <= N; i++) res[i] = i - 1;
    }
    for (ll i = 1; i <= N; i++) {
      if (i > 1) cout << " ";
      cout << res[i];
    }
    cout << endl;
  }

  return 0;
}

