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

  ll N; cin >> N;
  vector<ll> M(N);
  vector S(N, vector<ll>());
  REP(i, 0, N) {
    cin >> M[i];
    REP(j, 0, M[i]) {
      ll s; cin >> s;
      S[i].push_back(s);
    }
  }
  ll Q; cin >> Q;
  ll fail  = 0;
  REP(_q, 0, Q) {
    ll v, d; cin >> v >> d; v--; d--;
    if (S[v][d] == 0) {
      fail++;
    }else {
      S[v][d]--;
    }
  }
  REP(i, 0, N) {
    REPOUT(j, 0, M[i], S[i][j], " ");
  }
  cout << fail << endl;

  return 0;
}

