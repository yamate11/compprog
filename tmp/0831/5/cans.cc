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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


// @@ !! LIM()

using ordered_set = tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;  

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ordered_set os;
  ll N; cin >> N;
  // @InpVec (N, A) [mxLHA3VR]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [mxLHA3VR]
  ll rev = 0;
  REP(i, 0, N) {
    ll x = os.order_of_key(A[i]);
    rev += i - x;
    os.insert(A[i]);
  }
  cout << rev << "\n";
  REP(i, 0, N - 1) {
    rev = rev - A[i] + (N - A[i] - 1);
    cout << rev << "\n";
  }

  return 0;
}

