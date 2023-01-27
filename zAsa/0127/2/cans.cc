#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpGrid(2*N, M, A, type=char) [PFwFTuu4]
  auto A = vector(2*N, vector(M, char()));
  for (int i = 0; i < 2*N; i++) for (int j = 0; j < M; j++) { char v; cin >> v; A[i][j] = v; }
  // @End [PFwFTuu4]
  vector B(2*N, vector(M, 0LL));
  REP(i, 0, 2*N) REP(j, 0, M) B[i][j] = A[i][j] == 'G' ? 0 : A[i][j] == 'C' ? 1 : 2;
  vector<ll> win(2*N, 0LL);
  vector<ll> ord(2*N);
  REP(i, 0, 2*N) ord[i] = i;
  REP(i, 0, M) {
    REP(j, 0, N) {
      ll a = ord[2 * j];
      ll b = ord[2 * j + 1];
      ll ha = B[a][i];
      ll hb = B[b][i];
      if ((ha + 1) % 3 == hb) win[a]++;
      if ((hb + 1) % 3 == ha) win[b]++;
    }
    sort(ALL(ord), [&](ll a, ll b) -> bool {
      if (win[a] != win[b]) return win[a] > win[b];
      else return a < b;
    });
  }
  REPOUT(i, 0, 2*N, ord[i] + 1, "\n");
  return 0;
}

