#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

struct MyExc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> A(n - 1), B(n - 1);
  for (ll i = 0; i < n - 1; i++) cin >> A[i];
  for (ll i = 0; i < n - 1; i++) cin >> B[i];
  vector<ll> ans(n);
  for (ll p = 0; p < 2; p++) {
    vector<ll> XA(n - 1), XB(n - 1);
    for (ll i = 0; i < n - 1; i++) {
      XA[i] = (A[i] >> p) & 1;
      XB[i] = (B[i] >> p) & 1;
    }
    auto func = [&]() -> vector<ll> {
      vector<ll> ret(n);
      ll i = 0;
      for (; i < n - 1; i++) {
        if (XA[i] < XB[i]) throw MyExc();
        if (XA[i] == XB[i]) break;
      }
      if (i == n - 1) {
        for (ll j = 0; j < n; j++) ret[j] = j % 2;
        return ret;
      }
      ret[i] = XA[i];
      ret[i + 1] = XA[i];
      for (ll j = i + 1; j < n - 1; j++) {
        if (ret[j] == 1) {
          if (XA[j] == 0) throw MyExc();
          ret[j + 1] = XB[j];
        }else {
          if (XB[j] == 1) throw MyExc();
          ret[j + 1] = XA[j];
        }
      }
      for (ll j = i - 1; j >= 0; j--) {
        if (ret[j + 1] == 1) {
          if (XA[j] == 0) throw MyExc();
          ret[j] = XB[j];
        }else {
          if (XB[j] == 1) throw MyExc();
          ret[j] = XA[j];
        }
      }
      return ret;
    };
    try {
      auto C = func();
      for (ll i = 0; i < n; i++) ans[i] = (ans[i] | (C[i] << p));
    }catch(MyExc& e) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}

