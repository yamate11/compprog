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

  vector oo{1, 3, 5};
  vector ee{2, 6, 4};


  ll N; cin >> N;
  if (N == 3) {
    cout << "5 3 6\n9 7 2\n1 8 4\n";
    return 0;
  }

  vector A(N, vector(N, 0LL));
  vector used(N*N + 1, false);
  if (N % 2 != 0) {
    ll c = N / 2;
    ll n = 2, m = 1;
    REP(i, 0, N) {
      ll cc = i <= c ? c + 1 : c;
      ll n0, m0;
      if (i == c) { n0 = 1; m0 = 0; }
      else if (i == c + 1) { n0 = 2; m0 = 0; }
      else {
        n0 = n;
        m0 = m;
        m++;
        if (m == 3) { m = 0; n++; }
      }
      A[i][cc - 1] = 6 * n0 + oo[m0];
      A[i][cc    ] = 6 * n0 + ee[m0];
      used[6 * n0 + oo[m0]] = used[6 * n0 + ee[m0]] = true;
    }
    ll x = 1, y = 2;
    REP(i, 0, N) {
      ll cc = i <= c ? c + 1 : c;
      REP(j, 0, N) {
        if (A[i][j] > 0) continue;
        if (j < cc) {
          while (used[x]) x += 2;
          A[i][j] = x;
          x += 2;
        }else {
          while (used[y]) y += 2;
          A[i][j] = y;
          y += 2;
        }
      }
    }
  }else {
    ll c = N / 2;
    ll n = 0, m = 1;
    REP(i, 0, N) {
      A[i][c - 1] = 6 * n + oo[m];
      A[i][c]     = 6 * n + ee[m];
      used[6 * n + oo[m]] = used[6 * n + ee[m]] = true;
      if (m == 2) {
        m = 0;
        n++;
      }else {
        m++;
      }
    }
    ll x = 1;
    REP(i, 0, N) REP(j, 0, c) {
      if (A[i][j] > 0) continue;
      while (used[x]) x+= 2;
      A[i][j] = x;
      x += 2;
    }
    x = 2;
    REP(i, 0, N) REP(j, c, N) {
      if (A[i][j] > 0) continue;
      while (used[x]) x += 2;
      A[i][j] = x;
      x += 2;
    }
  }
  REP(i, 0, N) {
    REPOUT(j, 0, N, A[i][j], " ");
  }

  return 0;
}

