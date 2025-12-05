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
  ll M; cin >> M;
  vector<bool> done(N, false);
  vector<ll> vec(N, 0LL);
  ll ra = 0;
  ll pen = 0;
  REP(i, 0, M) {
    ll q; cin >> q; q--;
    string s; cin >> s;
    if (s == "WA") {
      vec[q]++;
    }else {
      if (not done[q]) {
        done[q] = true;
        ra ++;
        pen += vec[q];
      }
    }
  }
  cout << ra << " " << pen << endl;
  return 0;
}

