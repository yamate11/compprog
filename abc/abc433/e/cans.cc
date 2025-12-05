#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpVec(N, X, dec=1) [86QX75gs]
    auto X = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; X[i] = v; }
    // @End [86QX75gs]
    // @InpVec(M, Y, dec=1) [pCJx2vpD]
    auto Y = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; Y[i] = v; }
    // @End [pCJx2vpD]
    vector appX(N * M, -1LL);
    vector appY(N * M, -1LL);
    REP(i, 0, N) {
      if (appX[X[i]] >= 0) {
        cout << "No\n";
        return;
      }
      appX[X[i]] = i;
    }
    REP(i, 0, M) {
      if (appY[Y[i]] >= 0) {
        cout << "No\n";
        return;
      }
      appY[Y[i]] = i;
    }
    vector ans(N, vector(M, -1LL));
    vector<pll> vacant;
    vector<ll> filledX;
    vector<ll> filledY;

    REPrev(t, N * M - 1, 0) {
      ll i = appX[t];
      ll j = appY[t];
      if (i >= 0 and j >= 0) {
        ans[i][j] = t;
        for (ll jj : filledY) vacant.emplace_back(i, jj);
        for (ll ii : filledX) vacant.emplace_back(ii, j);
        filledX.push_back(i);
        filledY.push_back(j);
      }else if (i >= 0) {
        if (filledY.empty()) {
          cout << "No\n";
          return;
        }
        ans[i][filledY[0]] = t;
        REP(p, 1, ssize(filledY)) vacant.emplace_back(i, filledY[p]);
        filledX.push_back(i);
      }else if (j >= 0) {
        if (filledX.empty()) {
          cout << "No\n";
          return;
        }
        ans[filledX[0]][j] = t;
        REP(p, 1, ssize(filledX)) vacant.emplace_back(filledX[p], j);
        filledY.push_back(j);
      }else {
        if (vacant.empty()) {
          cout << "No\n";
          return;
        }
        auto [p, q] = vacant.back(); vacant.pop_back();
        ans[p][q] = t;
      }
    }
    cout << "Yes\n";
    REP(i, 0, N) {
      REPOUT(j, 0, M, ans[i][j] + 1, " ");
    }

  };


  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

