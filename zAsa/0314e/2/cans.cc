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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<string> v3 = {"aa.", "..a", "..a"};
  vector<string> v4 = {"abcc", "abdd", "eegh", "ffgh"};
  vector<string> v5 = {"aabbc", "h..ic", "h..id", "gjj.d", "gffee"};
  vector<string> v7 = {".aabbcc", "d.gg.hh", "di..a..", "ei..a..", "e.aa.aa", "fj..a..", "fj..a.."};
  ll N; cin >> N;
  if (N == 2) {
    cout << -1 << endl;
    return 0;
  }
  vector<string> brd(N, string(N, '.'));
  auto put = [&](ll a, auto& v) -> void {
    REP(i, 0, SIZE(v)) REP(j, 0, SIZE(v)) brd[a + i][a + j] = v[i][j];
  };
  if (N == 3) put(0, v3);
  else if (N == 6) { put(0, v3); put(3, v3); }
  else if (N == 7) put(0, v7);
  else if (N == 11) { put(0, v4); put(4, v7); }
  else {
    ll t = N / 4;
    ll r = N % 4;
    REP(i, 0, t - r) put(4 * i, v4);
    REP(j, 0, r) put(4 * (t - r) + 5 * j, v5);
  }
  REPOUT(i, 0, N, brd[i], "\n");

  return 0;
}

