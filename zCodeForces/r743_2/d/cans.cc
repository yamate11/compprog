#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector<ll> A(N);
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
      cin >> A[i];
      cnt += A[i];
    }
    if (cnt % 2 == 1) {
      cout << "NO\n";
      return;
    }
    vector<ll> ans;
    auto go = [&](ll i0) -> void {
      cout << "YES\n";
      ll i = i0;
      for (; i < N;) {
        for (; i < N && A[i] == 0; i++);
        if (i == N) break;
        // A[i-1] == 0; A[i] == 1
        assert(i+1 < N);
        if (A[i+1] == 1) {
          ans.push_back(i - 1);
          A[i] = A[i+1] = 0;
          i += 2;
        }else {
          // A[i-1] == 0; A[i] == 1; A[i+1] == 0
          assert(i+2 < N);
          if (A[i+2] == 1) {
            ans.push_back(i);
            A[i] = A[i+2] = 0;
            i += 3;
          }else {
            // A[i-1] == 0; A[i] == 1; A[i+1] == 0; A[i+2] == 0
            ans.push_back(i);
            ans.push_back(i-1);
            A[i] = 0;
            A[i + 2] = 1;
            i += 2;
          }
        }
      }
      if (ans.size() == 0) {
        cout << "0\n";
      }else {
        cout << ans.size() << "\n";
        for (ll a : ans) cout << a + 1 << " ";
        cout << "\n";
      }
    };
    if (A[0] == 0) {
      go(0);
      return;
    }else {
      for (ll i = 1;; i += 2) {
        assert(i != N);
        if (i+1 == N) {
          assert(A[i] == 1);
          cout << "NO\n";
          return;
        }
        if (A[i] == 0 && A[i + 1] == 0) {
          ans.push_back(i-1);
          A[i] = A[i+1] = 1;
        }else if (A[i] == 1 && A[i + 1] == 1) {
        }else {
          for (ll j = i - 1; j >= 0; j-= 2) {
            ans.push_back(j);
            A[j] = A[j+1] = A[j+2] = 0;
          }
          go(i + 1);
          return;
        }
      }
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

