#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n, a, b; cin >> n >> a >> b;
    ll x = n - a;
    if (a < b) x--;
    if (x < n / 2 - 1) {
      cout << "-1\n";
      return;
    }
    ll y = b - 1;
    if (a < b) y--;
    if (y < n / 2 - 1) {
      cout << "-1\n";
      return;
    }
    vector<bool> used(n + 1);
    cout << a << " ";
    used[a] = true;
    used[b] = true;
    ll t = n;
    ll cnt = 1;
    while (cnt < n / 2) {
      if (!used[t]) {
        used[t] = true;
        cout << t << " ";
        cnt++;
      }
      t--;
    }
    cout << b << " ";
    t = 1;
    cnt = 1;
    while (cnt < n / 2) {
      if (!used[t]) {
        used[t] = true;
        cout << t << " ";
        cnt++;
      }
      t++;
    }
    cout << endl;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

