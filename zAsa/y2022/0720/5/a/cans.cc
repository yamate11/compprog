#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

  ll N; cin >> N;
  string S; cin >> S;
  vector<ll> ans(3*N);
  vector<string> z = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
  REP(t, 6) {
    string ord = z[t];
    vector cnt(3, vector(3*N + 1, 0LL));
    REP(i, 3*N) {
      if (ans[i] > 0) continue;
      REP(y, 3) {
        if (y == S[i] - 'A') cnt[y][i + 1] = cnt[y][i] + 1;
        else                 cnt[y][i + 1] = cnt[y][i];
      }
    }
    ll p = 1;
    ll i0, j0;
    {
      ll i = 0, j = 3*N - 1;
      while (true) {
        i0 = i; j0 = j;
        while (i < 3*N and cnt[ord[0] - 'A'][i + 1] < p) i++;
        while (j >= 0 and cnt[ord[2] - 'A'][3*N] - cnt[ord[2] - 'A'][j] < p) j--;
        if (not (i < j and cnt[ord[1] - 'A'][j] - cnt[ord[1] - 'A'][i + 1] >= p)) {
          p--;
          break;
        }
        p++;
      }
    }
    REP(i, i0 + 1) if (ans[i] == 0 and S[i] == ord[0]) ans[i] = t + 1;
    REP2(j, j0, 3*N) if (ans[j] == 0 and S[j] == ord[2]) ans[j] = t + 1;
    ll c = 0;
    REP2(i, i0 + 1, j0) {
      if (ans[i] == 0 and S[i] == ord[1]) ans[i] = t + 1;
      c++;
      if (c == p) break;
    }
  }
  REP(i, 3*N) cout << ans[i];
  cout << endl;
  

  return 0;
}

