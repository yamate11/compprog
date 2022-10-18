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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<ll> P(N, -1);
  vector<ll> Q(N, -1);
  REP(i, 0, M) {
    ll a, b; cin >> a >> b; a--; b--;
    if (P[a] < 0) P[a] = b;
    else if (Q[a] < 0) Q[a] = b;
    else {
      cout << "No\n";
      return 0;
    }
    if (P[b] < 0) P[b] = a;
    else if (Q[b] < 0) Q[b] = a;
    else {
      cout << "No\n";
      return 0;
    }
  }
  REP(i, 0, N) {
    if (Q[i] < 0) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}

