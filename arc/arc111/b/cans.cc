#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/maxflow>
// #include <atcoder/all>
using namespace atcoder;

// @@ !! LIM()
// --> 
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
#if DEBUG
  const ll colMax = 400000;
#else
  const ll colMax = 400000;
#endif
  ll source = N + colMax + 1;
  ll sink = N + colMax + 2;
  mf_graph<int> d(N + colMax + 3);

  for (ll i = 0; i < N; i++) {
    d.add_edge(source, i, 1);
    d.add_edge(i, N + A[i], 1);
    d.add_edge(i, N + B[i], 1);
  }
  for (ll i = 1; i <= colMax; i++) {
    d.add_edge(N + i, sink, 1);
  }
  ll flow = d.flow(source, sink);
  cout << flow << endl;

  return 0;
}

