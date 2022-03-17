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
  vector<ll> A(N), B(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  ll hit = 0;
  REP(i, N) if (A[i] == B[i]) hit++;
  set<ll> aa;
  REP(i, N) aa.insert(A[i]);
  ll hitblow = 0;
  REP(i, N) if (aa.find(B[i]) != aa.end()) hitblow++;
  ll blow = hitblow - hit;
  cout << hit << endl;
  cout << blow << endl;
  

  return 0;
}

