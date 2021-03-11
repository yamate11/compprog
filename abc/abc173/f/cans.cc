#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll pts = 0;
  for (ll i = 0; i < N; i++) pts += (i + 1) * (N - i);
  ll edges = 0;
  for (ll i = 0; i < N-1; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    if (u > v) swap(u, v);
    edges += (u + 1) * (N - v);
  }
  cout << pts - edges << endl;


  return 0;
}

