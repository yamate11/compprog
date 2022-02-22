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

  ll N, M; cin >> N >> M;
  unordered_map<string, ll> mp;
  vector<string> S(N), T(M);
  vector<bool> stop(N);
  REP(i, N) {
    cin >> S[i];
    mp[S[i]] = i;
  }
  REP(i, M) {
    cin >> T[i];
    stop[mp[T[i]]] = true;
  }
  REP(i, N) {
    cout << (stop[i] ? "Yes\n" : "No\n");
  }
  

  return 0;
}

