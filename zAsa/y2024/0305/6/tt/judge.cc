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

void ac() {
  cout << "# AC" << endl;
  exit(0);
}

void wa(string msg = "") {
  cout << "# WA: " << msg << endl;
  exit(1);
}


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll M; cin >> M;
  // @InpVec(M, A, dec=1) [Crg2baSi]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [Crg2baSi]
  vector<ll> B(M);
  REP(i, 0, M) B[i] = i;
  REP(i, 0, N) {
    REP(j, 0, M) B[j] = A[B[j]];
  }
  REP(i, 0, M) cout << B[i] + 1 << " ";
  cout << endl;
  ll ans; cin >> ans;
  if (ans == N) ac();
  else wa();


  return 0;
}

