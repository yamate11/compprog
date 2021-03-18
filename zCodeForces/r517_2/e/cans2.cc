#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  auto func = [&]() -> pair<vector<pair<ll, ll>>, vector<ll>> {
    vector<pair<ll, ll>> v;
    vector<ll> w(A);

    auto rev = [&](ll start, ll step) -> void {
      v.emplace_back(start, step);
      for (ll i = 0; i < 3; i++) {
        ll& x = w[start + step*i];
        x = 1 - x;
      }
    };

    if (n >= 13) {
      ll p = n - 1;
      for ( ; ; ) {
        for ( ; p >= 12 && w[p] == 0; p--);
        if (p < 12) break;
        if (w[p-2] == 1 && w[p-1] == 1) rev(p-2, 1);
        else if (w[p-2] == 1 && w[p-1] == 0) rev(p-4, 2);
        else if (w[p-2] == 0 && w[p-1] == 0) rev(p-6, 3);
        else {
          vector<ll> z;
          for (ll i = 3; i <= 5; i++) if (w[p-i]) z.push_back(i);
          if (z.size() == 3) { rev(p-5, 2); rev(p-8, 4); }
          else if (z.size() == 2) {
            for (ll j = 0; j < 2; j++) rev(p-(z[j] + z[j] - j), z[j] - j);
          }else if (z.size() == 1) {
            rev(p - 2*z[0], z[0]);
            rev(p - 11, 5);
          }else if (z.size() == 0) { rev(p-2, 1); rev(p-10, 4); }
        }
      }
    }

    for (ll i = n - 3; i >= 0; i--) {
      if (w[i + 2] == 1) {
        w[i] = 1 - w[i];
        w[i + 1] = 1 - w[i + 1];
        w[i + 2] = 1 - w[i + 2];
        v.emplace_back(i, 1);
      }
    }
    w.resize(2);
    return {move(v), move(w)};
  };

  auto [v, w] = func();

  if (n >= 8) {
    for (ll i = 0; i < 2; i++) {
      if (w[i] == 1) {
        v.emplace_back(i, 3);
        v.emplace_back(i + 3, 1);
        v.emplace_back(i + 4, 1);
      }
    }
  }else {
    if (n == 7) {
      if (w[0] == 1 || w[1] == 0) {
        v.emplace_back(0, 3);
        v.emplace_back(3, 1);
        v.emplace_back(4, 1);
        w[0] = 0;
      }
    }
    if (w[0] != 0 || w[1] != 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  cout << v.size() << "\n";
  for (auto [start, step] : v) {
    for (ll j = 0; j < 3; j++) {
      if (j > 0) cout << " ";
      cout << start + step * j + 1;
    }
    cout << "\n";
  }
  return 0;
}

