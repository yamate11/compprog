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

// @@ !! LIM()

ll ask(auto& vec) {
  cout << "?";
  for (ll v : vec) cout << " " << v + 1;
  cout << endl;
  ll t; cin >> t;
  return t;
}

void fin(auto& vec) {
  cout << "!";
  for (ll v : vec) cout << " " << v;
  cout << endl;
  exit(0);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector fi(K + 1, 0LL);
  ll s = 0;
  REP(i, 0, K + 1) {
    vector<ll> vec;
    REP(j, 0, K + 1) if (j != i) vec.push_back(j);
    fi[i] = ask(vec);
    s += fi[i];
  }
  vector<ll> ans(N);
  REP(i, 0, K + 1) ans[i] = (fi[i] + s) % 2;
  REP(i, K + 1, N) {
    vector<ll> vec;
    REP(j, i - K + 1, i + 1) vec.push_back(j);
    ll p = ask(vec);
    REP(j, i - K + 1, i) p += ans[j];
    ans[i] = p % 2;
  }
  fin(ans);

  return 0;
}

