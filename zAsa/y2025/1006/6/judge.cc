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

  ll N, K; cin >> N >> K;
  vector<ll> ans(N);
  REP(i, 0, N) {
    ll a; cin >> a; ans[i] = a;
  }
  cout << N << " " << K << endl;
  REP(rep, 0, N) {
    string tp; cin >> tp;
    assert(tp == "?");
    ll ret = 0;
    REP(i, 0, K) {
      ll x; cin >> x; x--;
      ret += ans[x];
    }
    cout << ret % 2 << endl;
  }
  string tp2; cin >> tp2;
  assert(tp2 == "!");
  vector reported(N, 0LL);
  REP(i, 0, N) {
    ll y; cin >> y;
    reported[i] = y;
  }
  if (ans == reported) ac();
  else wa();

}

