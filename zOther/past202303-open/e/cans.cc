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

  ll H, W; cin >> H >> W;
  vector<ll> A(H), B(H);
  REP(i, 0, H) {
    string s; cin >> s;
    ll val = 0;
    REP(j, 0, W) if (s[j] == '#') val++;
    A[i] = val;
  }
  REP(i, 0, H) {
    string s; cin >> s;
    ll val = 0;
    REP(j, 0, W) if (s[j] == '#') val++;
    B[i] = val;
  }
  if (A == B) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

