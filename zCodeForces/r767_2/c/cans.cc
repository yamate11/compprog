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
    ll N; cin >> N;
    vector<ll> A(N);
    vector<ll> cnt(N + 1);
    REP(i, N) {
      cin >> A[i];
      cnt[A[i]]++;
    }
    ll mex = -1;
    REP(i, N + 1) {
      if (cnt[i] == 0) {
        mex = i;
        break;
      }
    }
    vector<ll> ans;
    ll i = 0;
    auto doit = [&]() -> ll {
      vector<bool> seen(N + 1);
      ll seen_cnt = 0;
      ll new_mex = mex;
      while (i < N) {
        ll a = A[i++];
        if (mex == 0) return 0;
        if (a > mex) continue;
        cnt[a]--;
        if (cnt[a] == 0) new_mex = min(new_mex, a);
        if (not seen[a]) {
          seen[a] = true;
          seen_cnt++;
          if (seen_cnt == mex) {
            return new_mex;
          }
        }
      }
      assert(0);
    };
    while (i < N) {
      ans.push_back(mex);
      mex = doit();
    }
    cout << SIZE(ans) << "\n";
    for (ll a : ans) cout << a << " ";
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

